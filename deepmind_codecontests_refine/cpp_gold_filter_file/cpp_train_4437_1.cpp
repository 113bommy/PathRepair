#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], b[N], ans[N], p[N];
bool cmp(int x, int y) { return b[x] < b[y]; }
int main() {
  int n;
  cin >> n;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); i++) scanf("%d", &b[i]), p[i] = i;
  sort(a + 1, a + n + 1);
  sort(p + 1, p + n + 1, cmp);
  for (int i = (1); i <= (n); i++) ans[p[i]] = a[n - i + 1];
  for (int i = (1); i <= (n); i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
