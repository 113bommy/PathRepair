#include <bits/stdc++.h>
template <typename T>
void read(T& x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
using namespace std;
const int N = 100010;
struct p {
  int x, v;
};
char s[N];
int sa[N], rk[N << 1], oldrk[N << 1], cnt[N], id[N], tmp[N];
int height[N];
p st[N];
bool cmp(int, int, int);
void suf_arr(char*, int*, int*, int*, int n, int m);
int main() {
  int n;
  int tail;
  long long ans;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  suf_arr(s, sa, rk, height, n, 300);
  height[n + 1] = 0;
  tail = 0;
  ans = 1LL * n * (n + 1) / 2;
  for (int i = 1; i <= n + 1; ++i) {
    int tmp = height[i], lst = i;
    while (tail && st[tail - 1].v > tmp) {
      int xl = st[tail - 1].x - 1, xr = i - 1, xlen = xr - xl + 1;
      int vl = max(st[tail - 2].v, tmp) + 1, vr = st[tail - 1].v,
          vlen = vr - vl + 1;
      ans += (1LL * xlen * (xlen + 1) / 2 - xlen) * vlen;
      lst = st[tail - 1].x;
      --tail;
    }
    if (tail && st[tail - 1].v == tmp) continue;
    st[tail++] = {lst, tmp};
  }
  printf("%lld", ans);
  return 0;
}
bool cmp(int x, int y, int w) {
  return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void suf_arr(char* s, int* sa, int* rk, int* height, int n, int m) {
  int p;
  memset(cnt, 0, (m + 1) * sizeof(int));
  memset(oldrk, 0, (2 * n + 1) * sizeof(int));
  for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
  for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; ++i) sa[cnt[rk[i]]--] = i;
  for (int w = 1, p = 0; w < n; w <<= 1, m = p, p = 0) {
    for (int i = n - w + 1; i <= n; ++i) id[++p] = i;
    for (int i = 1; i <= n; ++i) {
      if (sa[i] > w) id[++p] = sa[i] - w;
    }
    memset(cnt, 0, (m + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) ++cnt[tmp[i] = rk[id[i]]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[tmp[i]]--] = id[i];
    memcpy(oldrk, rk, (n + 1) * sizeof(int));
    p = 0;
    for (int i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
    height[rk[i]] = k;
  }
}
