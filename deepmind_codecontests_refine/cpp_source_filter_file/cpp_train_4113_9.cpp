#include <bits/stdc++.h>
using namespace std;
const int N = 500;
struct node {
  int x, y, val;
  node(int x, int y, int val) : x(x), y(y), val(val) {}
  bool operator<(const node &a) const { return a.val < val; }
};
int main() {
  int n;
  cin >> n;
  vector<node> arr;
  int vist[N] = {};
  for (int i = 2; i <= 2 * n; ++i) {
    for (int j = 1; j < i; ++j) {
      int x;
      cin >> x;
      arr.push_back(node(i, j, x));
    }
  }
  sort(arr.begin(), arr.end());
  vector<int> ans(2 * n + 1);
  for (int i = 0; i < arr.size(); ++i) {
    if (vist[arr[i].x] || vist[arr[i].y]) continue;
    vist[arr[i].x] = vist[arr[i].y] = 1;
    ans[arr[i].x] = arr[i].y;
    ans[arr[i].y] = arr[i].x;
  }
  for (int i = 1; i <= 2 * n; ++i) cout << ans[i] << " ";
  return 0;
}
