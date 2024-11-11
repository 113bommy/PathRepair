#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10, inf = 1000 * 1000;
int n, l, par[maxn];
long double dist[maxn], lef, rig, mat[maxn][maxn], b[maxn], x[maxn];
void print(int i) {
  if (i == n) {
    cout << i << endl;
    return;
  }
  if (i) cout << i << ' ';
  print(par[i]);
}
int main() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> b[i];
  }
  par[n] = n;
  lef = 0;
  rig = 1000000;
  while (lef + (0.000000001) < rig) {
    long double mid = (lef + rig) / 2;
    for (int i = 0; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        mat[i][j] = sqrt(abs((x[j] - x[i] - l))) - (mid * b[j]);
      }
    }
    for (int i = 0; i < n; i++) dist[i] = inf;
    dist[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j <= n; j++) {
        if (dist[i] > dist[j] + mat[i][j]) {
          par[i] = j;
          dist[i] = dist[j] + mat[i][j];
        }
      }
    }
    if (dist[0] <= 0) {
      rig = mid;
    } else {
      lef = mid + 0.000000001;
    }
  }
  print(0);
  return 0;
}
