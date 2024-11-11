#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e18 + 7;
const double PI = acos(-1);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
long long n, d, m;
struct node {
  int a, b;
  bool operator<(const node& other) const { return a < other.a; }
};
vector<node> vn;
long long seg[1000005 << 2];
void pushup(int rt) { seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]); }
void cha(int p, long long v, int l, int r, int rt) {
  if (l == r) {
    seg[rt] = min(seg[rt], v);
    return;
  }
  int m = (((l + r) >> 1));
  if (p <= m)
    cha(p, v, l, m, rt << 1);
  else
    cha(p, v, m + 1, r, rt << 1 | 1);
  pushup(rt);
}
long long que(int L, int R, int l, int r, int rt) {
  if (L <= l && R >= r) return seg[rt];
  ;
  int m = ((l + r) >> 1);
  long long res = maxn;
  if (L <= m) res = min(res, que(L, R, l, m, rt << 1));
  if (R > m) res = min(res, que(L, R, m + 1, r, rt << 1 | 1));
  return res;
}
int nxt[200050];
int sta[1000000];
int tol = 0;
int ins(int a) {
  while (tol >= 0 && vn[a].b <= vn[sta[tol]].b) tol--;
  sta[++tol] = a;
  if (tol != 0)
    return sta[tol - 1];
  else
    return -1;
}
int main() {
  cin >> d >> n >> m;
  int z = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    node nn;
    nn.a = a;
    nn.b = b;
    vn.push_back(nn);
    z = max(z, b);
  }
  node nn;
  nn.a = d;
  nn.b = 1;
  vn.push_back(nn);
  sort((vn).begin(), (vn).end());
  for (int i = ((int)(vn).size()) - 1; i >= 0; i--) {
    nxt[i] = ins(i);
  }
  long long ans = 0;
  long long now = n - vn[0].a;
  for (int i = 0; i < ((int)(vn).size()); i++) {
    int a = vn[i].a, b = vn[i].b;
    if (i != 0) now -= (a - vn[i - 1].a);
    if (now < 0) {
      ans = -1;
      break;
    }
    if (i == ((int)(vn).size()) - 1) break;
    if (vn[nxt[i]].a - a >= n) {
      ans += (n - now) * b;
      now = n;
    } else {
      long long zz = vn[nxt[i]].a - a;
      if (zz > now) {
        ans += (zz - now) * b;
        now = zz;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
