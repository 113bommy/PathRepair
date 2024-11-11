#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0, f = 1;
  char c;
  for (c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar())
    ;
  if (c == '-') c = getchar(), f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - 48;
  return n * f;
}
struct ar {
  int x, y, id, d;
} now;
bool operator<(ar a, ar b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
int i, a, b, d[3005];
vector<ar> p, an;
bool cmp(ar a, ar b) { return a.x * b.y > a.y * b.x; }
void solve(vector<ar> p) {
  int i, j, k, D, n = p.size() - 1;
  if (!n) return;
  for (i = 1; i <= n; i++)
    if (p[i] < p[0]) swap(p[i], p[0]);
  for (i = 1; i <= n; i++) p[i].x -= p[0].x, p[i].y -= p[0].y;
  sort(p.begin() + 1, p.end(), cmp);
  for (i = 1; i <= n; i++) p[i].x += p[0].x, p[i].y += p[0].y;
  if (p[0].d < 0) {
    for (i = 1; i <= n; i++) {
      j = i, D = 0;
      for (;; i++) {
        D += p[i].d;
        if (D >= 0) break;
      }
      p[i].d--, an.push_back((ar){p[i].id, p[0].id});
      p[i].d -= D;
      solve(vector<ar>(p.begin() + j, p.begin() + i + 1));
      p[j = i].d = D - 1;
      for (; D;) D += p[++i].d;
      solve(vector<ar>(p.begin() + j, p.begin() + i + 1));
    }
    return;
  }
  for (i = 1; p[0].d >= 0;) {
    for (j = i, D = 1; D; i++) D += p[i].d;
    p[0].d--, an.push_back((ar){p[0].id, p[i - 1].id});
    solve(vector<ar>(p.begin() + j, p.begin() + i));
  }
  solve(vector<ar>(p.begin() + i - 1, p.end()));
}
void work() {
  a = read(), b = read();
  for (i = 1; i <= b; i++) d[i] = read();
  p.clear(), an.clear();
  for (i = 1; i <= a + b; i++) {
    now.x = read(), now.y = read();
    if (i <= a)
      now.id = i, now.d = -1;
    else
      now.d = d[now.id = i - a] - 1;
    p.push_back(now);
  }
  solve(p);
  puts("YES");
  for (i = 0; i <= a + b - 2; i++) printf("%d%d\n", an[i].x, an[i].y);
}
int main() {
  for (int t = read(); t--;) work();
}
