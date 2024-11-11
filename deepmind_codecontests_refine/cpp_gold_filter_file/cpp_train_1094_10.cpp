#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
long long s[1000010];
double mx = -1e9;
pair<int, int> ans;
void Work(int m, int l, int r) {
  int Mid;
  long long tmp;
  while (l < r) {
    Mid = (l + r) >> 1;
    tmp = 1ll * (2 * Mid + 1) * (a[Mid + 1] + a[m + Mid + 1]) -
          2 * (s[Mid] + s[m + Mid]) + 2 * s[m - 1];
    if (tmp > 0)
      l = Mid + 1;
    else
      r = Mid;
  }
  double t = (s[r] + s[m + r] - s[m - 1]) / (2 * r + 1.0) - a[m];
  if (t > mx) mx = t, ans = make_pair(m, r);
}
bool cmp(int x, int y) { return x > y; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
  for (int i = 1; i <= n; i++) Work(i, 0, min(i - 1, n - i));
  printf("%d\n", ans.second * 2 + 1);
  for (int i = 1; i <= ans.second; i++) printf("%d ", a[i]);
  for (int i = ans.first; i <= ans.first + ans.second; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
