#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
  return sum;
}
int n;
map<int, int> mp;
map<int, int>::iterator it;
int col[600010];
char s[600010];
char ca[2];
int w[600010];
int nxt[600010];
const int inf = 0x7f7f7f7f;
struct seg_ {
  int mmin[600010 << 2];
  void up(int now) { mmin[now] = min(mmin[now << 1], mmin[now << 1 | 1]); }
  void build(int now, int l, int r) {
    mmin[now] = inf;
    if (l == r) return;
    int mid = l + r >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
  }
  void modify(int now, int l, int r, int t, int s) {
    if (l == r) return void(mmin[now] = min(mmin[now], s));
    int mid = l + r >> 1;
    if (t <= mid)
      modify(now << 1, l, mid, t, s);
    else
      modify(now << 1 | 1, mid + 1, r, t, s);
    up(now);
  }
  int query(int now, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return mmin[now];
    int mid = l + r >> 1;
    int u = inf;
    if (ll <= mid) u = min(u, query(now << 1, l, mid, ll, rr));
    if (rr >= mid + 1) u = min(u, query(now << 1 | 1, mid + 1, r, ll, rr));
    return u;
  }
} S;
__int128 Sum;
void add(int a, int b) {
  mp[a] += b;
  Sum += (__int128)a * b;
}
int sd[600010], num;
void up(int Val) {
  if (!mp.size()) return;
  it = mp.end();
  it--;
  int g = 0;
  num = 0;
  while (1) {
    int aa = (*it).first;
    int bb = (*it).second;
    if (aa <= Val) break;
    sd[++num] = aa;
    Sum -= (__int128)aa * bb;
    g += bb;
    if (it == mp.begin()) break;
    it--;
  }
  for (int i = 1; i <= num; i++) mp.erase(sd[i]);
  mp[Val] += g;
  Sum += (__int128)Val * g;
}
int Las[600010];
int qj(int l, int r) { return S.query(1, 1, n, l, r); }
const int G = (1 << 30) - 1;
void rr(__int128 a) {
  if (!a) return;
  short aa = a % 10;
  rr(a / 10);
  cout << aa;
}
void out(__int128 a) {
  if (!a)
    cout << 0 << '\n';
  else
    rr(a), cout << '\n';
}
int main() {
  n = read();
  S.build(1, 1, n);
  scanf("%s", &ca[1]);
  s[1] = ca[1];
  w[1] = read();
  S.modify(1, 1, n, 1, w[1]);
  __int128 ans = w[1];
  out(ans);
  for (int i = 2; i <= n; i++) {
    scanf("%s", &ca[1]);
    w[i] = read() ^ (ans & G);
    S.modify(1, 1, n, i, w[i]);
    s[i] = (char)((ca[1] - 'a' + ans % 26) % 26 + (int)'a');
    if (s[1] == s[i]) add(w[i], 1);
    col[i - 1] = s[i] - 'a';
    if (col[i - 1] == col[nxt[i - 1]])
      Las[i - 1] = Las[nxt[i - 1]];
    else
      Las[i - 1] = nxt[i - 1];
    int p = nxt[i - 1];
    while (p && s[p + 1] != s[i]) p = nxt[p];
    if (s[p + 1] == s[i]) nxt[i] = p + 1;
    p = nxt[i - 1];
    while (p) {
      if (col[p] != s[i] - 'a')
        add(qj(i - p, i - 1), -1), p = nxt[p];
      else
        p = Las[p];
    }
    up(w[i]);
    ans += Sum;
    ans += S.query(1, 1, n, 1, i);
    out(ans);
  }
  return 0;
}
