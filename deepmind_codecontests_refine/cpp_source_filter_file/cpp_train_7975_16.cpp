#include <bits/stdc++.h>
using namespace std;
int n, f[2005], ans1 = 0;
vector<int> v[2005], ans2;
struct nd {
  int t, d, p, id;
} a[105];
int cmp(nd x, nd y) { return x.d < y.d; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p), a[i].id = i;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++)
    for (int j = a[i].d - 1; j >= a[i].t; j--)
      if (f[j] < f[j - a[i].t] + a[i].p) {
        f[j] = f[j - a[i].t] + a[i].p;
        v[j].swap(v[j - a[i].t]);
        v[j].push_back(a[i].id);
      }
  for (int i = 0; i <= 2000; i++)
    if (f[i] > ans1) {
      ans1 = f[i];
      ans2 = v[i];
    }
  printf("%d\n%d\n", ans1, ans2.size());
  for (int i = 0; i < ans2.size(); i++) printf("%d ", ans2[i]);
  return 0;
}
