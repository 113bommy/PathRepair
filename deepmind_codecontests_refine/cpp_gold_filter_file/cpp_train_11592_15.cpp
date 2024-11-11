#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
int n, m, a[20], b[15][15], sumc[20], sumr[20], was[20], s, iter;
void Load() {
  cin >> n;
  m = n;
  n *= n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
bool check() {
  int cur = 0, i = 0, j = 0;
  for (i = 0; i < m; i++, j++) cur += b[i][j];
  if (cur != s) return false;
  cur = 0;
  for (i = 0, j = m - 1; i < m; i++, j--) cur += b[i][j];
  if (cur != s) return false;
  return true;
}
void go(int i, int j) {
  if (j == m) {
    if (sumr[i] != s) return;
    i++, j = 0;
  }
  if (i == m - 1 && j > 0) {
    if (sumc[j - 1] != s) return;
  }
  if (i == m) {
    if (check()) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) cout << b[i][j] << " ";
        cout << endl;
      }
      exit(0);
    }
    return;
  }
  iter++;
  if (iter > 10000) {
    if (i >= 1) return;
    iter = 0;
  }
  for (int k = 0; k < n; k++) {
    if (was[k]) continue;
    was[k] = 1;
    b[i][j] = a[k];
    sumc[j] += a[k];
    sumr[i] += a[k];
    go(i, j + 1);
    sumc[j] -= a[k];
    sumr[i] -= a[k];
    was[k] = 0;
  }
}
void Solve() {
  if (n == 1) {
    printf("%d\n%d", a[0], a[0]);
    return;
  }
  random_shuffle(a, a + n);
  s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  s /= m;
  printf("%d\n", s);
  go(0, 0);
}
int main() {
  Load();
  Solve();
  return 0;
}
