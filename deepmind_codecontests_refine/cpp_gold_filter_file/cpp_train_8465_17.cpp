#include <bits/stdc++.h>
using namespace std;
long long vx[1000005], vy[1000005], v[1000005];
int main() {
  int i, j;
  int n, m, a, b;
  cin >> n >> m;
  v[1] = 1;
  for (i = 2; i <= n; i++) v[i] = v[i - 1] * 7;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    vx[a] += v[b];
    vx[b] += v[a];
  }
  for (i = 1; i <= n; i++) vy[i] = vx[i] + v[i];
  sort(vy + 1, vy + n + 1);
  sort(vx + 1, vx + n + 1);
  long long total, s;
  total = s = 0;
  for (i = 1; i <= n; i++) {
    if (i == 1 || vx[i] != vx[i - 1]) {
      total += (s - 1) * s / 2;
      s = 1;
    } else
      s++;
  }
  total += s * (s - 1) / 2;
  s = 0;
  for (i = 1; i <= n; i++) {
    if (i == 1 || vy[i] != vy[i - 1]) {
      total += (s - 1) * s / 2;
      s = 1;
    } else
      s++;
  }
  total += s * (s - 1) / 2;
  cout << total << endl;
}
