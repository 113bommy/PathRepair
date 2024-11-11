#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL M = 1e9 + 7;
LL n, d[50], cn[51][51][51], sl[51][51], n3[51];
LL connect(LL twos, LL threes, LL after) {
  if (twos < 0 || threes < 0) return 0;
  LL &cur = cn[twos][threes][after];
  if (cur) return cur;
  if (after)
    return cur = (twos * connect(twos - 1, threes, after - 1) % M +
                  threes * connect(twos + 1, threes - 1, after - 1) % M) %
                 M;
  if (twos)
    return cur = ((twos - 1) * connect(twos - 2, threes, after) % M +
                  threes * connect(twos, threes - 1, after) % M) %
                 M;
  if (!threes) return 1;
  return cur =
             ((threes - 1) * (threes - 2) / 2) * connect(2, threes - 3, 0) % M;
}
LL solve(LL i, LL f) {
  if (i + f > n) return 0;
  if (i == n) return f == 0;
  if (f == 0) return 0;
  LL &cur = sl[i][f];
  if (~cur) return cur;
  LL r = 0, threes = n3[i + f] - n3[i], twos = f - threes;
  for (LL cl = 0; cl <= n - (i + f); cl++)
    r = (r + connect(twos, threes, cl) * solve(i + f, cl) % M) % M;
  return cur = r;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  memset(cn, -1, sizeof(cn));
  memset(sl, -1, sizeof(sl));
  cin >> n;
  for (LL i = 0; i < (n); i++) {
    cin >> d[i];
    n3[i + 1] = n3[i] + (d[i] == 3);
  }
  cout << solve(1, d[0]) << '\n';
}
