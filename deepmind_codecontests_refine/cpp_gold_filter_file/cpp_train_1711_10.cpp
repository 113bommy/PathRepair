#include <bits/stdc++.h>
using namespace std;
int a[500001], n, i, m, p[1000001];
vector<int> ans;
int main() {
  ios::sync_with_stdio(0);
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = 1;
  for (i = 1; i <= 1000000; i++)
    if (p[i] && p[1000001 - i] == 0) {
      p[i] = p[1000001 - i] = 2;
      ans.push_back(1000001 - i);
      m++;
    };
  if ((n - m) % 2 == 1) return -1;
  m = (n - m) / 2;
  for (i = 1; i <= 1000000; i++)
    if (p[i] == 0 && p[1000001 - i] == 0 && m)
      m--, ans.push_back(i), ans.push_back(1000001 - i);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
