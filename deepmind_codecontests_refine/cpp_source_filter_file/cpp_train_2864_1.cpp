#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const int MOD = 1000000007;
const int N = 1E5 + 15;
const int maxn = 2e5 + 14;
const int INF = (1 << 30) - 1;
const int letter = 130;
const double pi = acos(-1.0);
const double eps = 1e-8;
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, q;
long long a[N], b[N];
long long L[N], R[N];
int s[N], top;
void solve(int l, int r) {
  int cnt = 0;
  for (int i = l; i < r; i++) b[++cnt] = a[i];
  b[0] = INF;
  b[cnt + 1] = INF;
  s[top = 0] = 0;
  for (int i = 1; i <= cnt + 1; i++) {
    if (b[i] <= b[s[top]])
      s[++top] = i;
    else {
      while (top >= 0 && b[s[top]] < b[i]) R[s[top]] = i - s[top], top--;
      s[++top] = i;
    }
  }
  s[top = 0] = cnt + 1;
  for (int i = cnt; i >= 0; i--) {
    if (b[i] <= b[s[top]])
      s[++top] = i;
    else {
      while (top >= 0 && b[s[top]] <= b[i]) L[s[top]] = s[top] - i, top--;
      s[++top] = i;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= cnt; i++) {
    ans += L[i] * R[i] * b[i];
  }
  printf("%I64d\n", ans);
}
int main() {
  int x, y;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 1; i < n; i++) a[i] = abs(a[i + 1] - a[i]);
  while (q--) {
    scanf("%d%d", &x, &y);
    solve(x, y);
  }
  return 0;
}
