#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int c[N], n, cnt[26], fa[N], pre[N], nxt[N], pos[N], tt;
bool del[N];
char s[N];
set<int> S[N];
vector<pair<int, int> > opt;
void modify(int p, int v) {
  while (p <= n) c[p] += v, p += p & -p;
}
int query(int p) {
  int ret = 0;
  while (p) ret += c[p], p -= p & -p;
  return ret;
}
int getf(int x) { return x == fa[x] ? x : fa[x] = getf(fa[x]); }
void erase(int l, int r) {
  opt.push_back(make_pair(query(l - 1) + 1, query(r)));
  for (int i = getf(l); i <= r; i = getf(i)) modify(i, -1), fa[i] = i + 1;
}
void Delete(int k) {
  int l = pre[k], r = nxt[k];
  del[k] = 1;
  --cnt[s[pos[k]] - 'a'];
  nxt[l] = r;
  pre[r] = l;
  if (l != 1 && s[pos[l]] != s[pos[k]]) {
    S[s[pos[l]] - 'a'].erase(l);
    S[s[pos[k]] - 'a'].erase(l);
  }
  if (r <= tt && s[pos[k]] != s[pos[r]]) {
    S[s[pos[k]] - 'a'].erase(k);
    S[s[pos[r]] - 'a'].erase(k);
  }
  if (l != 1 && r <= tt && s[pos[l]] != s[pos[r]]) {
    S[s[pos[l]] - 'a'].insert(l);
    S[s[pos[r]] - 'a'].insert(l);
  }
}
int main() {
  int T = gi();
  while (T--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 0; i < 26; i++) S[i].clear(), cnt[i] = 0;
    opt.clear();
    tt = 0;
    for (int i = 1; i <= n; i++)
      if (i == 1 || s[i] == s[i - 1]) pos[++tt] = i, cnt[s[i] - 'a'] += i > 1;
    for (int i = 0; i <= n + 1; i++) fa[i] = i;
    for (int i = 0; i <= tt + 1; i++)
      pre[i] = i - 1, nxt[i] = i + 1, del[i] = 0;
    pre[0] = 0;
    nxt[tt + 1] = tt + 1;
    for (int i = 1; i <= n; i++) modify(i, 1);
    for (int i = 2; i < tt; i++)
      if (s[pos[i]] != s[pos[i + 1]]) {
        S[s[pos[i]] - 'a'].insert(i);
        S[s[pos[i + 1]] - 'a'].insert(i);
      }
    int sum = 0, mx = 0;
    for (int i = 0; i < 26; i++) {
      mx = max(mx, cnt[i]), sum += cnt[i];
    }
    cout << max((sum + 1) / 2, mx) + 1 << '\n';
    while (1) {
      int c = 0;
      for (int i = 1; i < 26; i++)
        if (cnt[i] > cnt[c]) c = i;
      if (S[c].empty()) break;
      int l = *S[c].begin(), r = nxt[l];
      erase(pos[l], pos[r] - 1);
      Delete(l);
      Delete(r);
    }
    for (int i = 2; i <= tt; i++)
      if (!del[i]) erase(1, pos[i] - 1);
    erase(1, n);
    for (auto t : opt) cout << t.first << ' ' << t.second << '\n';
  }
  return 0;
}
