#include <bits/stdc++.h>
using namespace std;
long long int n, m, k;
long long int a[128], b[128], c[128];
pair<long long int, long long int> pai[128][128][128];
long long int PD[128][128][128];
bool tem[128][128][128];
vector<pair<long long int, long long int> > resp;
long long int da(long long int u, long long int ant, long long int xi) {
  if (u == n) return 0;
  if (tem[u][ant][xi]) return PD[u][ant][xi];
  long long int cant = c[ant];
  long long int best = -1ll;
  for (long long int i = 0; i < m; i++)
    if (c[i] > cant) {
      long long int xim1 = a[ant] + xi;
      long long int x1;
      x1 = xim1 + k;
      if (x1 > 0 and a[i] <= x1 and x1 <= b[i]) {
        long long int tt = da(u + 1, i, x1 - a[i]);
        if (tt >= 0 and x1 + tt > best) {
          best = x1 + tt;
          pai[u][ant][xi] = pair<long long int, long long int>(i, x1 - a[i]);
        }
      }
      x1 = xim1 * k;
      if (x1 > 0 and a[i] <= x1 and x1 <= b[i]) {
        long long int tt = da(u + 1, i, x1 - a[i]);
        if (tt >= 0 and x1 + tt > best) {
          best = x1 + tt;
          pai[u][ant][xi] = pair<long long int, long long int>(i, x1 - a[i]);
        }
      }
    }
  tem[u][ant][xi] = true;
  return PD[u][ant][xi] = best;
}
void anda(long long int u, long long int ant, long long int xi) {
  if (u == n) return;
  pair<long long int, long long int> p = pai[u][ant][xi];
  cout << p.first + 1 << " " << a[p.first] + (long long int)p.second << endl;
  anda(u + 1, p.first, p.second);
}
int main() {
  cin >> n >> m >> k;
  for (long long int i = 0; i < m; i++) {
    long long int A, B;
    long long int C;
    cin >> A >> B >> C;
    a[i] = A;
    b[i] = B;
    c[i] = C;
  }
  memset(tem, false, sizeof(tem));
  long long int imaior, jmaior;
  imaior = jmaior = -1;
  long long int maior = -2ll;
  for (long long int i = 0; i < m; i++)
    for (long long int j = a[i]; j <= b[i]; j++) {
      long long int tt = da(1, i, j - a[i]);
      if (tt >= 0 and tt + j > maior) {
        maior = tt + j;
        imaior = i;
        jmaior = j;
      }
    }
  if (maior >= 0) {
    cout << "YES" << endl;
    cout << imaior + 1 << " " << jmaior << endl;
    anda(1, imaior, jmaior - a[imaior]);
  } else
    cout << "NO" << endl;
  return 0;
}
