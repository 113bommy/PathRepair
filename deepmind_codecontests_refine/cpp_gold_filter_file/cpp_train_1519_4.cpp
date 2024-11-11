#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long MAXK = 22;
long long n, k, tot, c[MAXK + 2], lst[MAXK + 2], cost[MAXK + 2][MAXK + 2],
    sec[MAXK];
long long tc[1 << MAXK], cc[2][1 << MAXK];
string s;
bool del[MAXK + 2], rmv[1 << MAXK];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> tot;
  cin >> s;
  for (char ch : s) del[ch - 'A'] = 1;
  int gg = 0;
  for (int i = 0; i < k; i++)
    if (del[i]) gg |= 1 << i;
  for (long long i = 0; i < k; i++) cin >> c[i];
  for (long long i = 0; i < k; i++)
    for (long long j = 0; j < k; j++) cin >> cost[i][j];
  for (long long i = 1; i < (1 << k); i++)
    for (long long j = 0; j < k; j++)
      if ((i >> j) & 1) {
        tc[i] = c[j] + tc[i ^ (1 << j)];
        break;
      }
  for (int i = 1; i < (1 << k); i++)
    for (int j = 0; j < k; j++)
      if ((i >> j) & 1) {
        rmv[i] = !del[j] | rmv[i ^ (1 << j)];
        break;
      }
  long long temp = (1 << k) - 1;
  memset(lst, -1, sizeof(lst));
  iota(sec, sec + k, 0);
  bool cur = 0;
  for (long long i = n - 1; ~i; i--) {
    long long ms = 0, z = s[i] - 'A';
    for (long long j = 0; j < k && ((ms >> z) & 1) == 0; j++)
      if (~lst[sec[j]]) {
        cc[cur][ms] += cost[z][sec[j]];
        if (z == sec[j])
          cc[cur][ms ^ (1 << z)] -= cost[z][sec[j]];
        else {
          cc[cur][ms ^ (1 << z)] -= cost[z][sec[j]];
          cc[cur][ms ^ (1 << sec[j])] -= cost[z][sec[j]];
          cc[cur][ms ^ (1 << z) ^ (1 << sec[j])] += cost[z][sec[j]];
        }
        ms |= 1 << sec[j];
      }
    lst[z] = i;
    long long j = 0;
    while (sec[j] != z) j++;
    while (j > 0) swap(sec[j], sec[j - 1]), j--;
  }
  for (long long i = 0; i < k; i++, cur = !cur)
    for (long long ms = 0; ms < (1 << k); ms++)
      if ((ms >> i) & 1)
        cc[!cur][ms] = cc[cur][ms] + cc[cur][ms ^ (1 << i)];
      else
        cc[!cur][ms] = cc[cur][ms];
  long long ans = 0;
  for (long long i = 0; i < (1 << k); i++)
    if (!rmv[i] && i != gg && cc[cur][i] + tc[i] <= tot) ans++;
  cout << ans << "\n";
  return 0;
}
