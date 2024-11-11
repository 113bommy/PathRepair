#include <bits/stdc++.h>
using namespace std;
int n, i;
pair<int, int> ans[110000], f[110000];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &f[i].first), f[i].second = i;
  sort(f, f + n);
  int nec = (n + 2) / 3;
  for (i = 0; i <= nec; i++)
    ans[f[i].second].first = 0, ans[f[i].second].second = f[i].first;
  int k = 0;
  for (i = nec + 1; i < n; i++) {
    if (k & 1) {
      ans[f[i].second].first = f[i].first - k / 2;
      ans[f[i].second].second = k / 2;
    } else {
      ans[f[i].second].second = f[i].first - k / 2;
      ans[f[i].second].first = k / 2;
    }
    k++;
  }
  puts("YES");
  for (i = 0; i < n; i++) printf("%d ", ans[i].first);
  puts("");
  for (i = 0; i < n; i++) printf("%d ", ans[i].second);
  return 0;
}
