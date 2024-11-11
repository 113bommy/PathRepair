#include <bits/stdc++.h>
using namespace std;
double maxy, y, d[3000];
int a[3000];
void tao() {
  freopen("input.inp", "w", stdout);
  cout << "1000 1000" << endl;
  for (int i = 1; i <= 1000; i++) cout << 1000 << " ";
}
int main() {
  int n, r;
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    maxy = 1.0 * r;
    for (int j = a[i] - 2 * r; j <= a[i] + 2 * r; j++)
      if (j > 0 && d[j] > 0.0) {
        y = d[j] + sqrt((2 * r) * (2 * r) - (a[i] - j) * (a[i] - j));
        maxy = max(y, maxy);
      }
    d[a[i]] = max(d[a[i]], maxy);
    printf("%.9lf ", maxy);
  }
  return 0;
}
