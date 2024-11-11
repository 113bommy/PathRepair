#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long odp = 1;
int n, m, t;
vector<long long> il(120, 0);
vector<bitset<120> > r(7);
bitset<120> zero;
void rec(int nr, long long ilo, int ileMam) {
  if (ileMam == 6) {
    odp = (odp + ilo) % MOD;
    return;
  }
  bitset<120> pr;
  pr = (((r[ileMam - 1] >> nr) | (r[ileMam - 1] << nr)) & zero);
  bitset<120> le;
  le = (((r[ileMam - 1] << nr) | (r[ileMam - 1] >> (m - nr))) & zero);
  r[ileMam] = (le | pr | r[ileMam - 1]);
  r[ileMam][nr] = r[ileMam][m - nr] = 1;
  odp = (odp + ilo) % MOD;
  for (int i = nr + 1; i < m / 2 + 1; ++i)
    if (il[i] != 0 && !r[ileMam][i] && !r[ileMam][m - i])
      rec(i, ilo * il[i] % MOD, ileMam + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> t;
  for (int i = 0; i < m; ++i) zero[i] = 1;
  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    x %= m;
    ++il[min(x, m - x)];
  }
  for (int i = 1; i < m / 2 + 1; ++i)
    if (il[i] != 0) rec(i, il[i], 1);
  cout << odp;
  return 0;
}
