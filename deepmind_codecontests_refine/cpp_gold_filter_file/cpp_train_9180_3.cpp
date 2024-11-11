#include <bits/stdc++.h>
using namespace std;
int n;
int a[600005], v[600005];
int sum[600005][3];
bool isvital[600005];
char s[600005], t[600005];
int transform() {
  int cur = 0, mini = 0, p = 0;
  for (int i = 1; i <= n; ++i) {
    cur += s[i] == '(' ? 1 : -1;
    if (mini > cur) {
      mini = cur;
      p = i;
    }
  }
  int total = 0;
  for (int i = p + 1; i <= n; ++i) t[++total] = s[i];
  for (int i = 1; i <= p; ++i) t[++total] = s[i];
  memcpy(s, t, sizeof(t));
  return p;
}
void solve(int t) {
  int last = 0, l = 0, r = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 2; ++j) sum[i][j] = sum[i - 1][j] + (v[i] == j);
  }
  for (int i = 1; i <= n; ++i)
    if (v[i] <= 1) {
      if (res < sum[n][0] + sum[i - 1][2] - sum[last][2]) {
        res = sum[n][0] + sum[i - 1][2] - sum[last][2];
        l = last + 1;
        r = i;
      }
      last = i;
    }
  last = 0;
  for (int i = 1; i <= n; ++i)
    if (!v[i]) {
      if (res < sum[i - 1][1] - sum[last][1]) {
        res = sum[i - 1][1] - sum[last][1];
        l = last + 1;
        r = i;
      }
      last = i;
    }
  printf("%d\n%d %d\n", res, (l + t - 1) % n + 1, (r + t - 1) % n + 1);
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int t = transform();
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(')
      a[i] = 1;
    else
      a[i] = -1;
    v[i] = v[i - 1] + a[i];
  }
  if (v[n]) {
    puts("0");
    puts("1 1");
    return 0;
  }
  solve(t);
}
