#include <bits/stdc++.h>
const int maxn = 6e5 + 9, mod = (1 << 30);
const long long L = 1000000000000000000;
int Read() {
  int x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
std::pair<long long, long long> operator+(
    const std::pair<long long, long long> A, const long long B) {
  return std::pair<long long, long long>((A.first + B) % L,
                                         A.second + (A.first + B) / L);
}
long long operator%(const std::pair<long long, long long> A,
                    const long long B) {
  return (A.first + A.second % B * (L % B) % B) % B;
}
namespace Sgt {
int tag[maxn << 2];
int mi[maxn << 2];
long long sum[maxn << 2], num[maxn << 2];
void Update(int nw) {
  mi[nw] = std::min(mi[nw << 1], mi[nw << 1 | 1]);
  sum[nw] = sum[nw << 1] + sum[nw << 1 | 1];
  num[nw] = num[nw << 1] + num[nw << 1 | 1];
}
void Pushdown(int nw) {
  int x(tag[nw]);
  if (x != -1) {
    tag[nw] = -1;
    tag[nw << 1] = x;
    tag[nw << 1 | 1] = x;
    mi[nw << 1] = x;
    mi[nw << 1 | 1] = x;
    sum[nw << 1] = 1ll * x * num[nw << 1];
    sum[nw << 1 | 1] = 1ll * x * num[nw << 1 | 1];
  }
}
void Build(int nw, int l, int r) {
  tag[nw] = -1;
  if (l == r) return;
  int mid(l + r >> 1);
  Build(nw << 1, l, mid);
  Build(nw << 1, mid + 1, r);
}
int Query(int nw, int l, int r, int lt, int rt, int x) {
  if (l == r) {
    if (mi[nw] >= x) return l;
    return l + 1;
  }
  if (lt <= l && rt >= r) {
    if (mi[nw] >= x) return l;
    Pushdown(nw);
    int mid(l + r >> 1);
    int ret(Query(nw << 1 | 1, mid + 1, r, lt, rt, x));
    if (ret == mid + 1) return Query(nw << 1, l, mid, lt, rt, x);
    return ret;
  }
  Pushdown(nw);
  int mid(l + r >> 1), ret(0);
  if (lt <= mid && rt > mid) {
    ret = Query(nw << 1 | 1, mid + 1, r, lt, rt, x);
    if (ret == mid + 1) return Query(nw << 1, l, mid, lt, rt, x);
    return ret;
  } else if (lt <= mid)
    return Query(nw << 1, l, mid, lt, rt, x);
  else
    return Query(nw << 1 | 1, mid + 1, r, lt, rt, x);
}
int Query(int nw, int l, int r, int x) {
  if (l == r) return mi[nw];
  Pushdown(nw);
  int mid(l + r >> 1);
  if (x <= mid)
    return Query(nw << 1, l, mid, x);
  else
    return Query(nw << 1 | 1, mid + 1, r, x);
}
void Modify(int nw, int l, int r, int lt, int rt, int x) {
  if (lt <= l && rt >= r) {
    tag[nw] = x;
    mi[nw] = x;
    sum[nw] = 1ll * num[nw] * x;
    return;
  }
  Pushdown(nw);
  int mid(l + r >> 1);
  if (lt <= mid) Modify(nw << 1, l, mid, lt, rt, x);
  if (rt > mid) Modify(nw << 1 | 1, mid + 1, r, lt, rt, x);
  Update(nw);
}
void Modify(int nw, int l, int r, int x, int v) {
  if (l == r) {
    num[nw] = v;
    sum[nw] = 1ll * v * mi[nw];
    return;
  }
  Pushdown(nw);
  int mid(l + r >> 1);
  if (x <= mid)
    Modify(nw << 1, l, mid, x, v);
  else
    Modify(nw << 1 | 1, mid + 1, r, x, v);
  Update(nw);
}
}  // namespace Sgt
int n;
int fail[maxn], dep[maxn], up[maxn][26], s[maxn];
void Update(int i) {
  if (i == 1) return;
  int j(fail[i - 1]);
  while (j && s[j + 1] != s[i]) j = fail[j];
  if (s[j + 1] == s[i])
    fail[i] = j + 1;
  else
    fail[i] = 0;
  for (int j = 0; j < 26; ++j) up[i][j] = up[fail[i]][j];
  up[i][s[fail[i] + 1]] = fail[i];
  dep[i] = dep[fail[i]] + 1;
}
int main() {
  dep[1] = 1;
  n = Read();
  Sgt::Build(1, 1, n);
  int last(0);
  std::pair<long long, long long> ans(std::pair<long long, long long>(0, 0));
  for (int i = 1; i <= n; ++i) {
    char c;
    scanf(" %c", &c);
    c -= 'a';
    c = (c + ans % 26) % 26;
    c += 'a';
    int x(Read());
    x ^= last;
    s[i] = c - 'a';
    Update(i);
    {
      int pre(i);
      if (i != 1) pre = Sgt::Query(1, 1, n, 1, i - 1, x);
      Sgt::Modify(1, 1, n, pre, i, x);
    }
    if (i != 1 && s[i] == s[1]) {
      Sgt::Modify(1, 1, n, i, 1);
    }
    ans = ans + Sgt::Query(1, 1, n, 1);
    {
      c = s[i];
      int nw(i - 1);
      while (true) {
        int nxt(0);
        for (int j = 0; j < 26; ++j)
          if (j ^ c) {
            if (dep[nxt] < dep[up[nw][j]]) {
              nxt = up[nw][j];
            }
          }
        if (nxt) {
          Sgt::Modify(1, 1, n, i - 1 - nxt + 1, 0);
          nw = nxt;
        } else
          break;
      }
    }
    ans = ans + Sgt::sum[1];
    last = ans % mod;
    if (ans.second) {
      printf("%lld%018lld\n", ans.second, ans.first);
    } else {
      printf("%lld\n", ans.first);
    }
  }
  return 0;
}
