#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int m, n, k, x, t;
string s;
vector<int> v;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i <= m; i++) {
    cin >> x;
    v.push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (__builtin_popcount(v[i] | v[m]) <= k) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
