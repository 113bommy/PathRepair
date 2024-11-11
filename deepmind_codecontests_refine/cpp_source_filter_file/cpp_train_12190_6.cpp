#include <bits/stdc++.h>
using namespace std;
int n, m;
void work() {
  long long d = n * (n - 1) / 2;
  long long Min = d, Max = d;
  for (int i = 1; i < n; i++) {
    d = d + i - (n - i);
    Min = min(Min, d);
    Max = max(Max, d);
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    int xi, di;
    scanf("%d %d", &xi, &di);
    if (di > 0)
      ans += n * xi + Max * di;
    else
      ans += n * xi + Min * di;
  }
  double Ans = ((double)ans) / n;
  printf("%.6lf\n", Ans);
}
int main() {
  cin >> n >> m;
  work();
  return 0;
}
