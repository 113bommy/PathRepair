#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const long long maxn = 2e5 + 700;
const int mod = 1e9 + 7;
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
long long n, m, p;
char s[maxn];
int a[maxn], b[maxn];
int digit(long long x, int *d) {
  int ans = 0;
  while (x) {
    d[++ans] = x % 10;
    x /= 10;
  }
  return ans;
}
int path[maxn];
int check(int pos, int lbound, int rbound) {
  if (!pos) return 1;
  if (!lbound && !rbound) return 1;
  int l = lbound ? a[pos] : 0;
  int r = rbound ? b[pos] : 9;
  for (int i = l; i <= r; i++) {
    if (path[i] > 0) {
      int f = 0;
      path[i]--;
      if (check(pos - 1, lbound && i == l, rbound && i == r)) f = 1;
      path[i]++;
      if (f) return 1;
    }
  }
  return 0;
}
int pos, res = 0;
void dfs(int u, int w) {
  if (u == 9) {
    path[u] = w;
    if (check(pos, 1, 1)) res++;
    return;
  }
  for (int i = 0; i <= w; i++) {
    path[u] = i;
    dfs(u + 1, w - i);
  }
}
int main() {
  read(n);
  read(m);
  pos = digit(n, a);
  pos = digit(m, b);
  dfs(0, pos);
  printf("%d\n", res);
  return 0;
}
