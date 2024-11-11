#include <bits/stdc++.h>
using namespace std;
mt19937 nima(time(0));
const long long max_n = 4e3 + 20, MOD = 1e9 + 7;
long long mx, ans, cnt, sum, R, L, r, l;
long long a[max_n];
string s[max_n];
long long mark[max_n][max_n], mark1[max_n][max_n];
long long n, k, m, x[4], y[4];
vector<long long> v;
string pass;
int32_t main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++)
      if (s[i][j] == '*') {
        y[cnt] = i;
        x[cnt] = j;
        cnt++;
      }
  for (long long i = 0; i < 3; i++)
    for (long long j = 0; j < 100; j++) mark[y[i]][j] = 1;
  for (long long i = 0; i < 3; i++)
    for (long long j = 0; j < 100; j++) {
      mark1[j][x[i]] = 1;
      if (mark[j][x[i]] && mark1[j][x[i]] && s[j][x[i]] != '*') l = j, r = x[i];
    }
  cout << l + 1 << " " << r + 1;
  return 0;
}
