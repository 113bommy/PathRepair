#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const long long MAXN = 2e5 + 11;
long long tmp[MAXN], N, M, K, Lim;
struct Segment {
  long long Sum[MAXN << 2], tag[MAXN << 2];
  void Init() {
    memset(Sum, 0, sizeof(Sum)), memset(tag, 0, sizeof(tag));
    return;
  }
  void pushup(long long k, long long l, long long r) {
    if (tag[k])
      Sum[k] = tmp[r] - tmp[l - 1];
    else
      Sum[k] = Sum[k << 1] + Sum[k << 1 | 1];
    return;
  }
  void Add(long long k, long long l, long long r, long long x, long long y,
           long long w) {
    if (x <= l && r <= y) {
      tag[k] += w;
      pushup(k, l, r);
      return;
    }
    long long mid = (l + r) >> 1;
    if (x <= mid) Add(k << 1, l, mid, x, y, w);
    if (mid < y) Add(k << 1 | 1, mid + 1, r, x, y, w);
    pushup(k, l, r);
    return;
  }
} S;
long long X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];
long long Num[MAXN], tot;
struct node {
  long long L, R, ps, w;
} E[MAXN];
bool cmp(node x1, node x2) { return x1.ps < x2.ps; }
void ins(long long x1, long long y1, long long x2, long long y2) {
  if (x1 > x2 || y1 > y2) return;
  tmp[++tmp[0]] = x1 - 1, tmp[++tmp[0]] = x2;
  ++tot;
  E[tot].L = x1, E[tot].R = x2, E[tot].ps = y1, E[tot].w = 1;
  ++tot;
  E[tot].L = x1, E[tot].R = x2, E[tot].ps = y2 + 1, E[tot].w = -1;
  return;
}
long long calc(long long r) {
  tot = 0;
  tmp[0] = 0;
  S.Init();
  long long all = 0;
  for (long long i = 1; i <= M; i++)
    ins((X1[i] - 1) / (1 << r) + 1, (Y1[i] - 1) / (1 << r) + 1,
        X2[i] / (1 << r), Y2[i] / (1 << r));
  sort(tmp + 1, tmp + tmp[0] + 1);
  sort(E + 1, E + tot + 1, cmp);
  Lim = unique(tmp + 1, tmp + tmp[0] + 1) - tmp - 1;
  for (long long i = 1; i <= tot; i++)
    E[i].L = lower_bound(tmp + 1, tmp + Lim + 1, E[i].L) - tmp,
    E[i].R = lower_bound(tmp + 1, tmp + Lim + 1, E[i].R) - tmp;
  tmp[0] = 0;
  for (long long i = 1, j = 1; i <= tot; i = j) {
    all += (E[i].ps - E[i - 1].ps) * S.Sum[1];
    while (E[i].ps == E[j].ps && j <= tot)
      S.Add(1, 1, Lim, E[j].L, E[j].R, E[j].w), ++j;
  }
  return all;
}
signed main() {
  N = read(), M = read(), K = read();
  for (long long i = 1; i <= M; i++)
    X1[i] = read(), Y1[i] = read(), X2[i] = read(), Y2[i] = read();
  long long res = 0;
  while ((1 << (res + 1)) <= K) res++;
  for (long long i = 0; i <= res; i++) Num[i] = calc(i);
  for (long long i = 0; i <= res; i++) {
    if ((Num[i] - Num[i + 1]) & 1) {
      printf("Hamed\n");
      return 0;
    }
  }
  printf("Malek\n");
  return 0;
}
