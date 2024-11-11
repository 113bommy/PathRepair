#include <bits/stdc++.h>
int bsf(int x) { return __builtin_ctz(x); }
int bsr(int x) { return 31 - __builtin_clz(x); }
using namespace std;
const double pi = 3.14159265358979323846;
const int inf = (int)2e+9 + 2;
const int mod = (int)1e+9 + 7;
const double eps = 1e-8;
const int N = 200000;
int n, m, k;
vector<vector<int>> a;
int s[N];
void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
      s[i] += a[i][j];
    }
  }
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < static_cast<int>(a[i].size()); ++j) {
      int val = s[i] - a[i][j];
      if (auto it = mp.find(val); it != mp.end() && it->second != i) {
        cout << "YES\n";
        cout << i + 1 << ' ' << j + 1 << '\n';
        for (int q = 0; q < static_cast<int>(a[it->second].size()); ++q) {
          if (s[it->second] - a[it->second][q] == val) {
            cout << it->second + 1 << ' ' << q + 1;
            break;
          }
        }
        return;
      } else {
        mp.emplace(val, i);
      }
    }
  }
  cout << "NO";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int test = 1;
  for (; test; --test) solve();
  return 0;
}
