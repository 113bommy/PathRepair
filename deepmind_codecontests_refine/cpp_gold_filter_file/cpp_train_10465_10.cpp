#include <bits/stdc++.h>
using namespace std;
typedef int arr32[40100];
typedef long long arr64[40100];
struct str {
  int x, y;
} dot[40100];
arr32 nex, pas, mark, val, line;
arr64 sum;
long long ans;
int n, m, q, p;
bool cmp(const str &a, const str &b) { return (a.x < b.x); }
int main() {
  scanf("%d %d %d %d", &n, &m, &p, &q);
  for (int i = 1; i <= p; i++) {
    scanf("%d %d", &dot[i].x, &dot[i].y);
  }
  sort(dot + 1, dot + p + 1, cmp);
  int bg = 1;
  for (int U = 1; U <= n; U++) {
    for (; bg <= p && dot[bg].x < U; bg++)
      ;
    memset(mark, 0, sizeof(mark));
    memset(val, 0, sizeof(val));
    nex[0] = m + 1;
    pas[m + 1] = 0;
    for (int u = bg; u <= p; u++) mark[dot[u].y] = 1;
    for (int i = 1; i <= m; i++) {
      if (!mark[i]) continue;
      nex[i] = m + 1;
      pas[i] = pas[m + 1];
      pas[nex[i]] = i;
      nex[pas[i]] = i;
    }
    for (int u = bg; u <= p; u++) val[dot[u].y]++;
    int ed = p;
    int top = 0;
    for (int D = n; D >= U; D--) {
      for (; ed >= bg && dot[ed].x == D; ed--) {
        int R = dot[ed].y, L = dot[ed].y;
        int js = 0;
        for (; L > 0 && js < q; L = pas[L]) js += val[L];
        for (int tims = 0; tims <= q && R <= m; R = nex[R], tims++) {
          for (; js > q && L < dot[ed].y; L = nex[L]) js -= val[nex[L]];
          if (js == q && L < dot[ed].y) {
            line[++top] = D;
            sum[top] = (long long)(nex[R] - R) * (long long)(nex[L] - L);
          }
          js += val[nex[R]];
        }
        if (!(--val[dot[ed].y])) {
          nex[pas[dot[ed].y]] = nex[dot[ed].y];
          pas[nex[dot[ed].y]] = pas[dot[ed].y];
        }
      }
    }
    long long js = 0;
    for (int D = U; D <= n; D++) {
      for (; top > 0 && line[top] == D; top--) js += sum[top];
      ans += js;
    }
  }
  cout << ans << endl;
  return 0;
}
