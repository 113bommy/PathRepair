#include <bits/stdc++.h>
using namespace std;
bool flag;
int n, a[1010], vis[2010], T;
pair<int, int> ans[5];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
bool check(int step) {
  for (int i = 1; i <= n; i++)
    if (a[i] != i) return 0;
  return 1;
}
void rev(int *a, int l, int r) {
  for (int i = 0; i <= (r - l - 1) / 2; i++) swap(a[i + l], a[r - i]);
}
int expect() {
  int ans = 1;
  for (int i = 2; i <= n; i++)
    if (abs(a[i] - a[i - 1]) != 1) ans++;
  return ans;
}
void dfs(int step) {
  if (check(step - 1)) {
    printf("%d\n", step - 1);
    for (int i = step - 1; i; i--)
      printf("%d %d\n", ans[i].first, ans[i].second);
    flag = 1;
    return;
  }
  if (step > 3) return;
  int c[1010];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++)
      if (abs(a[i - 1] - a[j]) == 1 && abs(a[i] - a[j + 1]) == 1) {
        for (int k = i; k <= j; k++) c[k] = a[k];
        rev(a, i, j);
        if (expect() <= (3 - step) * 2 + 1) {
          ans[step] = make_pair(i, j);
          dfs(step + 1);
          if (flag) return;
        }
        for (int k = i; k <= j; k++) a[k] = c[k];
      }
  }
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  a[n + 1] = n + 1;
  dfs(1);
  return 0;
}
