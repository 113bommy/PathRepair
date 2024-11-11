#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double RRR = 180.0 / PI;
const long double EPS = 1e-8;
int main() {
  string s1, s2;
  int n, k, t, x, y;
  char c1, c2;
  string name[256];
  int nomer[256], minuta[256], gos[256], hom[256];
  cin >> s1;
  cin >> s2;
  cin >> n;
  memset(gos, 0, sizeof(gos));
  memset(hom, 0, sizeof(hom));
  k = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> c1 >> y >> c2;
    if (c2 == 'r') {
      if ((c1 == 'h') && (hom[y] == 2)) continue;
      if ((c1 == 'a') && (gos[y] == 2)) continue;
      k++;
      if (c1 == 'h')
        name[k] = s1;
      else
        name[k] = s2;
      nomer[k] = y;
      minuta[k] = x;
      if (c1 == 'h')
        hom[y] = 2;
      else
        gos[y] = 2;
    } else {
      if (c1 == 'h' && hom[y] < 2) {
        hom[y]++;
        if (hom[y] == 2) {
          k++;
          name[k] = s1;
          nomer[k] = y;
          minuta[k] = x;
        }
      } else if (c1 == 'a' && gos[y] < 2) {
        gos[y]++;
        if (gos[y] == 2) {
          k++;
          name[k] = s2;
          nomer[k] = y;
          minuta[k] = x;
        }
      }
    }
  }
  for (int i = 1; i <= k; i++)
    cout << name[i] << " " << nomer[i] << " " << minuta[i] << endl;
  return 0;
}
