#include <bits/stdc++.h>
using namespace std;
const long long MaX = 100005, infi = 1110111110111, mod = 1000000007;
const int MX = 200005;
int n, m, q, sTree[MX][22], a[MX], sP[MX], eP[MX], fir, wi;
int query(int a, int b) {
  int lgn = log2(b - a + 1);
  return min(sTree[a][lgn], sTree[b - (1 << (lgn)) + 1][lgn]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> sTree[i][0];
    if (sTree[i][0] == 0)
      sTree[i][0] = MX - 1;
    else if (!fir)
      fir = sTree[i][0];
    if (!sP[sTree[i][0]]) sP[sTree[i][0]] = i;
    eP[sTree[i][0]] = i;
    m = max(m, sTree[i][0]);
    wi |= sTree[i][0] == q;
  }
  if (m < q) return cout << "NO", 0;
  for (int j = 1; j < 21; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++)
      sTree[i][j] = min(sTree[i][j - 1], sTree[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i <= n; i++) {
    int x = sTree[i][0];
    if (x == MX - 1) {
      if (!wi)
        sTree[i][0] = q, m = 0;
      else if (sTree[i - 1][0] > 0)
        sTree[i][0] = sTree[i - 1][0];
      else
        sTree[i][0] = fir;
    } else if (query(sP[x], eP[x]) < x)
      return cout << "NO", 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << sTree[i][0] << " ";
  return 0;
}
