#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 3e5 + 123;
const int PRI = 555557;
const int pri = 997;
int tests = 1;
int n, m, k;
string s;
int cnt[31];
int cur, res;
inline void Solve() {
  cin >> s;
  int n = s.size();
  if (s.size() & 1) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    return;
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) ++cnt[s[i] - '0'];
  for (int i = n - 1; i >= 0; i--) {
    --cnt[s[i] - '0'];
    cur = s[i] - '0';
    for (int j = cur - 1; j >= 0; j--) {
      if (!i && !j) break;
      s[i] = j + '0';
      ++cnt[j];
      static vector<int> v;
      v.clear();
      for (int j = 0; j < 10; j++)
        if (cnt[j] & 1) v.push_back(j);
      if (v.size() <= n - 1 - i && (n - 1 - i - v.size()) % 2 == 0) {
        for (int r = n - 1, l = 0; r > i; r--, l++) {
          if (l < v.size())
            s[r] = '0' + v[l];
          else
            s[r] = '9';
        }
        cout << s;
        return;
      }
      --cnt[j];
    }
    s[i] = cur + '0';
  }
  for (int i = 0; i < n - 1; i++) cout << 9;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> tests;
  while (tests--) {
    Solve();
    cout << '\n';
  }
  return 0;
}
