#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n, rk[1000 + 5];
pair<int, int> stu[1000 + 5];
void clean() {}
void solve() {
  scanf("%d", &n);
  clean();
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &stu[i].first, &stu[i].second);
  }
  int now = stu[1].first;
  for (int i = 1; i <= n; i++) {
    int l = stu[i].first, r = stu[i].second;
    if (now <= r)
      now = max(now + 1, l + 1), rk[i] = now - 1;
    else
      rk[i] = 0;
  }
  for (int i = 1; i <= n; i++) printf("%d ", rk[i]);
  putchar('\n');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
