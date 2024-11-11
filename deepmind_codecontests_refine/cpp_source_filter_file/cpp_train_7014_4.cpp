#include <bits/stdc++.h>
using namespace std;
int n, m, q[100010], c[200010], f[200010], tot, inf = 2e9, nwt[200010], cnt;
pair<pair<int, int>, int> p[100010];
pair<int, int> P[200010];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
int find(int x) { return (f[x] == x) ? x : f[x] = find(f[x]); }
inline bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}
int main() {
  read(m);
  read(n);
  for (int i = 1; i <= m; i++) {
    read(p[i].first.first);
    read(p[i].first.second);
    read(p[i].second);
    c[++tot] = p[i].first.first;
    c[++tot] = p[i].first.second;
  }
  for (int i = 1; i <= n; i++) read(q[i]);
  sort(c + 1, c + tot + 1);
  sort(p + 1, p + m + 1, cmp);
  tot = unique(c + 1, c + tot + 1) - (c + 1);
  for (int i = 1; i <= tot; i++) f[i] = i, nwt[i] = -inf;
  for (int i = 1; i <= m; i++) {
    int x = lower_bound(c + 1, c + tot + 1, p[i].first.first) - c,
        y = lower_bound(c + 1, c + tot + 1, p[i].first.second) - c;
    for (int j = find(x); j < y; j = find(j)) {
      f[j] = j + 1;
      nwt[j] = p[i].second;
    }
  }
  for (int i = 1; i <= tot; i++)
    if (nwt[i] != -inf) {
      P[++cnt].first = nwt[i] - c[i];
      P[cnt].second = -1;
      P[++cnt].first = nwt[i] - c[i + 1];
      P[cnt].second = 1;
    }
  sort(P + 1, P + cnt + 1);
  long long ans = 0, K = 0;
  int now = 1;
  for (int i = 1; i <= n; i++) {
    for (; now <= cnt && P[now].first <= q[i]; now++) {
      ans -= P[now].first * P[now].second;
      K += P[now].second;
    }
    printf("%I64d\n", ans + K * q[i]);
  }
  return 0;
}
