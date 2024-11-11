#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int N, M;
string s[100];
long long d[1 << 20];
long double f[1 << 20];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin >> N;
  for (int(i) = 0, j123 = N; (i) < j123; (i)++) cin >> s[i];
  M = s[0].size();
  for (int(i) = 0, j123 = N; (i) < j123; (i)++)
    for (int(j) = 0, j123 = N; (j) < j123; (j)++)
      if (i != j) {
        int same = 0;
        for (int(k) = 0, j123 = M; (k) < j123; (k)++)
          if (s[i][k] == s[j][k]) same |= (1 << k);
        d[same] |= (1LL << i);
      }
  for (int mask = (1 << M) - 1; mask >= 0; mask--)
    for (int(i) = 0, j123 = M; (i) < j123; (i)++)
      if (!((mask >> i) & 1)) d[mask] |= d[mask | (1 << i)];
  for (int mask = (1 << M) - 1; mask >= 0; mask--) {
    if (d[mask] == 0) continue;
    long double tot = 0;
    int cnt = 0;
    for (int(i) = 0, j123 = M; (i) < j123; (i)++)
      if (!((mask >> i) & 1)) {
        cnt++;
        tot += f[mask | (1 << i)] * __builtin_popcountll(d[mask | (1 << i)]) /
               __builtin_popcountll(d[mask]);
      }
    tot /= cnt;
    tot += 1;
    f[mask] = tot;
  }
  cout << f[0] << '\n';
}
