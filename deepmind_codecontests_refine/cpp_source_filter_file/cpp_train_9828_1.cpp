#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5, INF = 2e9 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, a[MAXN], p[MAXN], cnt, Cnt[MAXN];
long long ans;
priority_queue<int, vector<int>, greater<int> > q;
int tmp[MAXN];
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i] = read(), ans += a[i];
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); i++) p[i] = a[i];
  cnt = unique(p + 1, p + n + 1) - p - 1;
  for (int i = (1); i <= (n); i++)
    a[i] = lower_bound(p + 1, p + cnt + 1, a[i]) - p, Cnt[a[i]]++;
  int tot = 0;
  for (int i = (cnt); i >= (1); i--) {
    int pp = min(Cnt[i], tot - 2 * (int)q.size()), N = 0,
        rst = min(Cnt[i] - pp, tot - pp);
    for (int i = (1); i <= (pp); i++) tmp[++N] = p[i];
    for (int j = 1; j <= rst; j += 2) {
      int k = q.top();
      q.pop();
      if (k < p[i])
        tmp[++N] = p[i], j < rst ? tmp[++N] = p[i] : 0;
      else
        tmp[++N] = k, j < rst ? tmp[++N] = 2 * p[i] - k : 0;
    }
    for (int i = (1); i <= (N); i++)
      if (tmp[i] >= 0) q.push(tmp[i]);
    tot += Cnt[i];
  }
  for (; !q.empty();) ans -= q.top(), q.pop();
  cout << ans << "\n";
  return 0;
}
