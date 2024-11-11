#include <bits/stdc++.h>
using namespace std;
const int maxn = 1024;
int n, k, m;
int belong[maxn + 5], l[maxn + 5], r[maxn + 5];
bool f[maxn + 5];
int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  char op[2];
  scanf("%s", op);
  if (op[0] == 'N') return 1;
  return 0;
}
void Reset() {
  puts("R");
  fflush(stdout);
}
void Report(int ans) {
  printf("! %d\n", ans);
  fflush(stdout);
}
void Query(int id) {
  for (int i = l[id]; i <= r[id]; ++i) f[i] &= query(i);
}
int main() {
  cin >> n >> k;
  if (k == 1) k = 2;
  for (int i = 1; i <= n; ++i) belong[i] = (i - 1) / (k / 2) + 1;
  for (int i = 1; i <= n; ++i) {
    if (belong[i - 1] != belong[i]) l[belong[i]] = i;
    r[belong[i]] = i;
  }
  m = belong[n];
  for (int i = 1; i <= n; ++i) f[i] = true;
  for (int d = 1; d < m; ++d)
    for (int s = 1; s <= d && s + d <= m; ++s) {
      Reset();
      for (int i = s; i <= m; i += d) Query(i);
    }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (f[i]) ++ans;
  Report(ans);
  return 0;
}
