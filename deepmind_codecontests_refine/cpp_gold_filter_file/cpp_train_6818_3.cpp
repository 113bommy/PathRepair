#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, inf = (1 << 30);
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
int inp, fl;
char cr;
inline int read() {
  inp = fl = 0, cr = getchar();
  while (cr < '0' || cr > '9') fl = (cr == '-'), cr = getchar();
  while (cr >= '0' && cr <= '9') inp = (inp * 10) + (cr ^ 48), cr = getchar();
  return fl ? -inp : inp;
}
int n, m, a[MAXN], b[MAXN], ans;
int gap[1005], k;
bool gap_used[1005] = {0};
bool used[MAXN] = {0};
int f[MAXN], g[MAXN];
vector<int> vt[MAXN];
int findPre(int x) {
  int l = 0, r = n, mid, res;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (g[mid] < x)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
void dfs(int last, int K) {
  if (!K) return;
  int len = vt[K].size();
  for (int i = 0; i < len; ++i)
    if (vt[K][i] < last && a[vt[K][i]] < a[last]) return dfs(vt[K][i], K - 1);
  for (int i = k; i >= 1; --i)
    if (gap[i] < last && !gap_used[i]) {
      int pos = lower_bound(b + 1, b + 1 + m, a[last]) - b - 1;
      used[pos] = 1, gap_used[i] = 1, a[gap[i]] = b[pos], dfs(gap[i], K - 1);
      break;
    }
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    if (a[i] == -1) gap[++k] = i;
  }
  m = read();
  for (int i = 1; i <= m; ++i) b[i] = read();
  sort(b + 1, b + 1 + m), memset(g, 0x3f, sizeof g), g[0] = 0;
  int p1, p2, pre;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      p1 = n - 1, p2 = m;
      while (p1 >= 0 && p2) {
        if (b[p2] > g[p1]) {
          if (b[p2] < g[p1 + 1]) g[p1 + 1] = b[p2];
          ans = max(ans, p1 + 1), --p2;
        } else
          --p1;
      }
    } else {
      pre = findPre(a[i]);
      if (a[i] < g[pre + 1]) g[pre + 1] = a[i];
      f[i] = pre + 1, ans = max(ans, f[i]);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] != -1) vt[f[i]].push_back(i);
  bool ok = 0;
  for (int i = n; i; --i)
    if (f[i] == ans) {
      dfs(i, ans - 1), ok = 1;
      break;
    }
  if (!ok) {
    a[gap[k]] = b[m], used[m] = 1, gap_used[k] = 1, dfs(gap[k], ans - 1);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != -1)
      printf("%d ", a[i]);
    else
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          used[j] = 1, printf("%d ", b[j]);
          break;
        }
  }
}
