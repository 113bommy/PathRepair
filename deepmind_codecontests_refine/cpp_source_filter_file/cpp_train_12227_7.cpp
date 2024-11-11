#include <bits/stdc++.h>
const int MAXN = 555;
int N, M;
int v[MAXN];
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", v + i);
  }
  double ans = 0;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double val = v[a] + v[b];
    val /= c;
    if (val > ans) {
      ans = val;
    }
  }
  printf("%lf\n", ans);
  return 0;
}
