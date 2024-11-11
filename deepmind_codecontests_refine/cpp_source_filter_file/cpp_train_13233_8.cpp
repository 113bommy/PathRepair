#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
long long sum = 0;
map<long long, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  int ai;
  for (int i = 0; i < n; ++i) {
    cin >> ai;
    a.push_back(ai);
    m[ai] += 1;
    sum += ai;
  }
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    int ts = sum - a[i];
    int tr;
    if (ts % 2 == 0 && ts / 2 == a[i]) {
      tr = 1;
    } else {
      tr = 0;
    }
    if (ts % 2 == 0 && m[ts / 2] > tr) {
      res.push_back(i + 1);
    }
  }
  cout << res.size() << "\n";
  for (int it : res) {
    cout << it << " ";
  }
  return 0;
}
