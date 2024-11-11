#include <bits/stdc++.h>
using namespace std;
const int maxn = 51000;
char s[maxn];
struct node {
  int sc, pos;
  bool operator<(const node &a) const { return sc < a.sc; }
} da[maxn];
long long val[maxn << 2], lazy[maxn << 2], Q, M;
void pushDown(int x, int s) {
  lazy[x << 1] += lazy[x];
  lazy[x << 1 | 1] += lazy[x];
  val[x << 1] += lazy[x];
  val[x << 1 | 1] += lazy[x];
  lazy[x] = 0;
}
void updata(int l, int r, int v, int s = M, int x = 1) {
  if (l <= 1 && r >= s) {
    lazy[x] += v;
    val[x] += v;
    return;
  }
  pushDown(x, s);
  if (l <= s / 2) updata(l, r, v, s / 2, x << 1);
  if (r > s / 2) updata(l - s / 2, r - s / 2, v, s - s / 2, x << 1 | 1);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
void qu(int l, int r, int s = M, int x = 1) {
  if (l <= 1 && r >= s) {
    Q = min(Q, val[x]);
    return;
  }
  pushDown(x, s);
  if (l <= s / 2) qu(l, r, s / 2, x << 1);
  if (r > s / 2) qu(l - s / 2, r - s / 2, s - s / 2, x << 1 | 1);
}
void query(int l, int r) {
  Q = ~(1u << 64);
  qu(l, r);
}
int main() {
  int m = 0, a, b;
  long long ans = 0;
  gets(s);
  M = strlen(s);
  for (int i = 0; i < M; i++) {
    if (s[i] == '?') s[i] = '(', da[m++].pos = i;
    if (s[i] == '(') updata(i + 1, M, 1);
    if (s[i] == ')') updata(i + 1, M, -1);
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    ans += a;
    da[i].sc = b - a;
  }
  sort(da, da + m);
  for (int i = 0; i < m; i++) {
    updata(da[i].pos + 1, M, -2);
    if (val[1] >= 0)
      s[da[i].pos] = ')', ans += da[i].sc;
    else
      updata(da[i].pos + 1, M, 2);
  }
  query(M, M);
  if (Q != 0 && val[1] >= 0)
    cout << -1 << endl;
  else {
    cout << ans << endl;
    cout << s << endl;
  }
}
