#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  vector<string> vec(n);
  for (long long i = 0; i < n; ++i) cin >> vec[i];
  bool ch1 = 0;
  for (long long i = 0; i < n; ++i) {
    bool a = 0, b = 0;
    for (long long j = 0; j < m; ++j) {
      if (vec[i][j] == '#') {
        a = 1;
        if (b) {
          cout << -1;
          return 0;
        }
      } else if (a)
        b = 1;
    }
    if (!a) {
      ch1 = 1;
    }
  }
  bool ch2 = false;
  for (long long j = 0; j < m; ++j) {
    bool a = 0, b = 0;
    for (long long i = 0; i < n; ++i) {
      if (vec[i][j] == '#') {
        a = 1;
        if (b) {
          cout << -1;
          return 0;
        }
      } else if (a)
        b = 1;
    }
    if (!a) ch2 = 1;
  }
  if (ch1 ^ ch2) {
    cout << -1;
    return 0;
  }
  long long cnt = 0;
  long long i = 0;
  bool ch = false;
  for (long long j = 0; j < m; ++j)
    if (vec[i][j] == '#') ch = 1;
  if (ch) ++cnt;
  for (long long i = 1; i < n; ++i) {
    bool nxt = 1, req = 0;
    for (long long j = 0; j < m; ++j) {
      if (vec[i][j] == '#') req = 1;
      if (vec[i][j] == '#' && vec[i - 1][j] == '#') nxt = 0;
    }
    if (nxt && req) ++cnt;
  }
  cout << cnt;
}
