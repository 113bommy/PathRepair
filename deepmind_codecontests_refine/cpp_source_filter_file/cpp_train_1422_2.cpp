#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n, T;
int a[200005], t[200005];
long long sumat[200005], suma[200005];
struct Data {
  int x, y;
} data[200005];
bool cmp(Data a, Data b) { return a.y < b.y; }
int main() {
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d", &data[i].x);
  for (int i = 1; i <= n; i++) scanf("%d", &data[i].y);
  sort(data + 1, data + 1 + n, cmp);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || t[i] != t[i - 1]) {
      tot++;
      a[tot] = data[i].x;
      t[tot] = data[i].y;
    } else
      a[tot] += data[i].x;
  }
  n = tot;
  for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + (long long)a[i];
  for (int i = 1; i <= n; i++)
    sumat[i] = sumat[i - 1] + (long long)a[i] * (long long)t[i];
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i] >= T) break;
    double x;
    x = (double)((sumat[n] - sumat[i]) - T * (suma[n] - suma[i])) /
        (double)(T - t[i]);
    if (x - eps <= a[i] && x + eps >= 0) ans = max(ans, suma[n] - suma[i] + x);
  }
  for (int i = n; i >= 1; i--) {
    if (t[i] <= T) break;
    double x;
    x = (double)(T * suma[i - 1] - sumat[i - 1]) / (double)(t[i] - T);
    if (x - eps <= a[i] && x + eps >= 0) ans = max(ans, suma[i - 1] + x);
  }
  int summ = 0;
  for (int i = 1; i <= n; i++)
    if (t[i] == T) summ += a[i];
  ans = max(ans, (double)summ);
  printf("%.10lf", ans);
}
