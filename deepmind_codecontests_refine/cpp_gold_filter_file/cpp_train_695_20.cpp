#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int n;
struct task {
  int a, b;
  double w;
} t[N];
bool cmp(task a, task b) { return a.a > b.a; }
bool cmp2(task a, task b) { return a.w < b.w; }
double f[2][N];
bool ok(double x) {
  x /= 1e4;
  for (int i = 1; i <= n; i++) t[i].w = t[i].a - x * t[i].b;
  memset(f, 127, sizeof f);
  int o = 0;
  f[o][0] = 0;
  for (int i = 1; i <= n;) {
    double sum = 0;
    int j = i;
    for (; j <= n && t[i].a == t[j].a; sum += t[j].w, j++)
      ;
    sort(t + i, t + j, cmp2);
    int sz = j - i;
    o = 1 - o;
    memset(f[o], 127, sizeof f[o]);
    for (int k = 0; k <= sz; k++, sum -= t[j - k].w) {
      for (int j = k; j < i; j++) {
        f[o][j - k + (sz - k)] = min(f[o][j - k + (sz - k)], f[1 - o][j] + sum);
      }
    }
    i = j;
  }
  for (int i = 0; i <= n; i++)
    if (f[o][i] <= 1e-7) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &t[i].a);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i].b);
  long long l = 0, r = 1e8 * 1e4, ans = r;
  sort(t + 1, t + 1 + n, cmp);
  while (l <= r) {
    if (ok(l + r >> 1)) {
      ans = r = (l + r >> 1);
      r--;
    } else
      l = (l + r >> 1) + 1;
  }
  cout << ans / 10 + (ans % 10 != 0) << endl;
}
