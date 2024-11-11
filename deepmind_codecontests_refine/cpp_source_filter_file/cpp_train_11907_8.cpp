#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
int p[MAXN];
double pr[MAXN][MAXN];
double cpy[MAXN][MAXN];
void update(int n, int a, int b) {
  if (a > b) swap(a, b);
  for (int k = 1; k <= n; k++) {
    cpy[a][k] = pr[a][k];
    cpy[k][a] = pr[k][a];
    cpy[b][k] = pr[a][k];
    cpy[k][b] = pr[k][b];
  }
  for (int k = 1; k <= n; k++) {
    if (k < a) {
      pr[k][a] = 0.5 * (cpy[k][a] + cpy[k][b]);
      pr[k][b] = pr[k][a];
    } else if (b < k) {
      pr[a][k] = 0.5 * (cpy[a][k] + cpy[b][k]);
      pr[b][k] = pr[a][k];
    } else if (a < k && k < b) {
      pr[a][k] = 0.5 * cpy[a][k] + 0.5 * (1 - cpy[k][b]);
      pr[k][b] = 0.5 * cpy[k][b] + 0.5 * (1 - cpy[a][k]);
    }
  }
  pr[a][b] = 0.5;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      pr[i][j] = p[i] > p[j];
    }
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    update(n, a, b);
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += pr[i][j];
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
