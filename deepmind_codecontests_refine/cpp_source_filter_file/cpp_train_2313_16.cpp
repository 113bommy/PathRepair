#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
}
using namespace std;
const long long P = 1e18;
const int mask = (1 << 30) - 1;
const int inf = 1e9 + 100;
template <typename T>
inline void MIN(T &a, T b) {
  if (b < a) a = b;
}
int n;
pair<long long, long long> ans;
inline pair<long long, long long> operator+(const pair<long long, long long> &a,
                                            const long long x) {
  return make_pair((a.first + x) % P, a.second + (a.first + x) / P);
}
inline int operator%(const pair<long long, long long> &a, const int x) {
  return (a.first + (a.second % x * (P % x) % x)) % x;
}
int w[601000], s[601000];
int fail[601000][26];
int ls[601000 << 2], rs[601000 << 2], val[601000 << 2], root, ttot;
void build(int L, int R, int &cur) {
  cur = ++ttot;
  val[cur] = inf;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(L, mid, ls[cur]), build(mid + 1, R, rs[cur]);
}
void modify(int L, int R, int pos, int x, int cur) {
  MIN(val[cur], x);
  if (L == R) return;
  int mid = (L + R) >> 1;
  if (pos <= mid)
    modify(L, mid, pos, x, ls[cur]);
  else
    modify(mid + 1, R, pos, x, rs[cur]);
}
int query(int L, int R, int l, int r, int cur) {
  if (l <= L && R <= r) return val[cur];
  int mid = (L + R) >> 1, res = inf;
  if (l <= mid) res = query(L, mid, l, r, ls[cur]);
  if (r > mid) MIN(res, query(mid + 1, R, l, r, rs[cur]));
  return res;
}
int query(int l, int r) { return query(1, n, l, r, root); }
inline void Print(pair<long long, long long> pr) {
  if (pr.second)
    printf("%lld%018lld\n", pr.second, pr.first);
  else
    printf("%lld\n", pr.first);
}
map<int, int> mp;
inline void init() {
  ans = make_pair(0, 0);
  build(1, n, root);
  char ch[3];
  scanf("%s", ch);
  s[1] = ch[0] - 'a';
  read(w[1]);
  modify(1, n, 1, w[1], root);
  ans = ans + w[1];
  Print(ans);
}
int nxt[601000];
int main() {
  read(n);
  ans = make_pair(0, 0);
  build(1, n, root);
  init();
  int ptr = 0;
  long long nwres = 0;
  for (int i = 2; i <= n; ++i) {
    char ch[3];
    scanf("%s", ch);
    s[i] = (ch[0] - 'a' + (ans % 26)) % 26;
    read(w[i]);
    w[i] ^= (ans % (mask + 1));
    modify(1, n, i, w[i], root);
    if (s[i] == s[1]) nwres += w[i], ++mp[w[i]];
    ans = ans + query(1, i);
    for (int c = 0; c < 26; ++c)
      if (c != s[i]) {
        int p = fail[i - 1][c];
        while (p) {
          int v = query(p, i - 1);
          nwres -= v;
          --mp[v];
          p = fail[p][c];
        }
      }
    while (ptr && s[ptr + 1] != s[i]) ptr = nxt[ptr];
    if (s[ptr + 1] == s[i]) ++ptr;
    nxt[i] = ptr;
    for (int c = 0; c < 26; ++c) fail[i][c] = fail[ptr][c];
    fail[i][s[ptr + 1]] = ptr;
    int cnt = 0;
    for (map<int, int>::iterator it = mp.upper_bound(w[i]); it != mp.end();
         ++it) {
      cnt += it->second;
      nwres -= 1ll * it->second * it->first;
    }
    mp.erase(mp.upper_bound(w[i]), mp.end());
    mp[w[i]] += cnt;
    nwres += 1ll * cnt * w[i];
    ans = ans + nwres;
    Print(ans);
  }
  return 0;
}
