#include <bits/stdc++.h>
using namespace std;
int l[100010];
int r[100010];
int flag[100010];
double m[100010];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    flag[i] = (r[i] / p) - (l[i] - 1) / p;
    m[i] = r[i] - l[i] + 1;
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (flag[i]) {
      ans += 4000 * (flag[i] / m[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int next = i + 1;
    if (next > n) next = 1;
    if (flag[i] && flag[next]) {
      ans -= 2000.0 * (flag[i] / m[i]) * (flag[next] / m[next]);
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
