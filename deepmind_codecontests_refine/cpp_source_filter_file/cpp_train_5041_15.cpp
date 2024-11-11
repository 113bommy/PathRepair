#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long long X = 1e7;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int c[N], f[N][26], d[30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  s = '*' + s + '*';
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j <= 25; j++) f[i][j] = f[i + 1][j];
    f[i][s[i] - 'a'] = i;
  }
  int mx = 0;
  for (long long i = 1; i <= n; i++) {
    int ind[27], cnt = 0;
    for (long long x = 0; x <= 25; x++) ind[x] = f[i][x];
    sort(ind + 0, ind + 25 + 1);
    ind[26] = n + 1;
    for (long long x = 0; x <= 25; x++)
      if (ind[x] != 0) {
        cnt += 1;
        d[cnt] += ind[x + 1] - ind[x];
      }
    mx = max(mx, cnt);
  }
  cout << mx << "\n";
  for (long long i = 1; i <= mx; i++) cout << d[i] << "\n";
}
