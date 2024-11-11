#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, i, j, k, q, s, w, v, ans;
int a[2 * N];
double b[2 * N], mean[2 * N];
int main() {
  double c;
  cin >> n >> k >> c;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    b[i] = a[i] + b[i - 1];
    mean[i] = (mean[i - 1] + a[i]) / c;
  }
  cin >> m;
  for (j = 1; j <= m; j++) {
    cin >> s;
    double real = (b[s] - b[s - k]) / k;
    double approx = mean[s] / k;
    cout << fixed << setprecision(6);
    printf("%.6f %.6f %.6f\n", real, approx, abs(real - approx) / real);
  }
  return 0;
}
