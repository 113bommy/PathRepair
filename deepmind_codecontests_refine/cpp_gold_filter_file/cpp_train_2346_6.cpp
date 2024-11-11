#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node {
  string s;
  int num, val;
  node() {}
  node(string s, int num, int val) : s(s), num(num), val(val) {}
};
bool operator<(const node a, const node b) {
  if (a.num == b.num) {
    return a.val > b.val;
  }
  return a.num < b.num;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<node> arr(n);
  for (int k = (int)(0); k < (int)(n); k++) {
    string s;
    int num, val;
    cin >> s >> num >> val;
    arr[k] = node(s, num, val);
  }
  sort(arr.begin(), arr.end());
  vector<bool> was(m);
  for (int k = (int)(0); k < (int)(n - 1); k++) {
    if (arr[k].num == arr[k + 1].num && !was[arr[k].num - 1]) {
      if (k != n - 2 && arr[k].num == arr[k + 2].num &&
          arr[k + 1].val == arr[k + 2].val) {
        cout << "?\n";
      } else {
        cout << arr[k].s << " " << arr[k + 1].s << '\n';
      }
      was[arr[k].num - 1] = true;
    }
  }
  return 0;
}
