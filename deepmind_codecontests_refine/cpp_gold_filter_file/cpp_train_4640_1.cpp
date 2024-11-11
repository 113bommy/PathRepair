#include <bits/stdc++.h>
using namespace std;
ifstream fin("Sisend.txt");
long long n, k, s, t, c[200005], v[200005], g[200005];
bool saab(long long ke) {
  long long su = 0;
  for (int(i) = (0); ((i)) < ((k)); ((i))++) {
    long long va = g[i];
    if (i) va -= g[i - 1];
    if (ke < va) return 0;
    if (ke >= 2 * va)
      su += va;
    else
      su += 2 * va - ke % va;
  }
  if (su <= t) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n >> k >> s >> t;
  for (int(i) = (0); ((i)) < ((n)); ((i))++) cin >> c[i] >> v[i];
  for (int(i) = (0); ((i)) < ((k)); ((i))++) cin >> g[i];
  g[k] = s;
  k++;
  sort(g, g + k);
  long long l = 0, r = 2e9;
  while (l < r) {
    long long ke = (l + r) / 2;
    if (!saab(ke))
      l = ke + 1;
    else
      r = ke;
  }
  long long hind = 2e9;
  for (int(i) = (0); ((i)) < ((n)); ((i))++)
    if (v[i] >= l) hind = min(hind, c[i]);
  if (hind == 2e9)
    cout << -1;
  else
    cout << hind;
}
