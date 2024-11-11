#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const unsigned long long p = 19260817;
inline int read(int x = 0, char c = getchar(), bool f = 0) {
  while (c < '0' || c > '9') f = c == '-', c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
int n, m, k;
int c[300050], dp[300050], al[300050];
vector<int> v[300050];
vector<unsigned long long> hs[300050];
unsigned long long po[300050];
bool cmp(const int &a, const int &b) { return c[a] < c[b]; }
int pd[300050], pd2[300050];
map<int, int> mp[300050];
inline unsigned long long geths(int id, int l, int r) {
  --l;
  --r;
  if (!l) return hs[id][r];
  return hs[id][r] - hs[id][l - 1] * po[r - l + 1];
}
inline void del1(int);
inline void del2(int);
inline void del1(int id) {
  if (!pd[id]) return;
  pd[id] = 0;
  for (map<int, int>::iterator x = mp[id].begin(); x != mp[id].end(); ++x)
    del2((*x).first);
  mp[id].clear();
}
inline void del2(int id) {
  if (!pd2[id]) return;
  pd2[id] = 0;
  for (int i = 0; i < v[id].size(); ++i) del1(v[id][i]);
  v[id].clear();
  return;
}
inline void work(int a, int pos, int b) {
  int len = min(v[a].size() - pos + 1, v[b].size());
  if (geths(a, pos, pos + len - 1) != geths(b, 1, len)) {
    del2(a);
    del2(b);
  } else {
    pd2[b] = 0;
    int ok = 1;
    for (int j = len, x; j < v[b].size(); ++j) {
      x = v[b][j];
      v[a].push_back(x);
      hs[a].push_back(p * hs[a][hs[a].size() - 1] + x);
      if (pd[x]) {
        if (mp[x][a]) {
          ok = 0;
        } else
          mp[x][a] = v[a].size();
      } else
        ok = 0;
    }
    if (!ok) del2(a);
  }
}
int cnt[300050];
int main() {
  n = read();
  m = read();
  k = read();
  po[0] = 1;
  for (int i = 1; i <= 300000; ++i) po[i] = po[i - 1] * p;
  for (int i = 1; i <= n; ++i) pd2[i] = 1;
  for (int i = 1; i <= k; ++i) pd[i] = 1;
  for (int i = 1, ok; i <= n; ++i) {
    c[i] = read();
    ok = 1;
    for (int j = 1, x; j <= c[i]; ++j) {
      x = read();
      v[i].push_back(x);
      if (j == 1)
        hs[i].push_back(x);
      else
        hs[i].push_back(p * hs[i][hs[i].size() - 1] + x);
      if (pd[x]) {
        if (mp[x][i])
          ok = 0;
        else
          mp[x][i] = j;
      } else
        ok = 0;
    }
    if (!ok) del2(i);
  }
  for (int i = 1, t; i <= n; ++i) {
    if (!pd2[i]) continue;
    t = v[i][0];
    if (!pd[t] || mp[t].size() == 1) continue;
    for (map<int, int>::iterator x = mp[t].begin(); x != mp[t].end(); ++x) {
      if ((*x).first == i || !pd2[(*x).first]) continue;
      work((*x).first, (*x).second, i);
      break;
    }
    if (mp[t][i]) mp[t].erase(mp[t].find(i));
  }
  for (int i = 1, len; i <= k; ++i) {
    if (!pd[i]) continue;
    len = 0;
    for (map<int, int>::iterator x = mp[i].begin(); x != mp[i].end(); ++x) {
      if (!pd2[(*x).first]) continue;
      if (len) {
        del2(i);
        break;
      } else
        len = 1;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (pd2[i]) ++cnt[v[i].size()];
  for (int i = 1; i <= k; ++i)
    if (pd[i] && !mp[i].size()) ++cnt[1];
  for (int i = 1; i <= k; ++i)
    if (cnt[i]) al[++al[0]] = i;
  dp[0] = 1;
  for (int j = 0; j <= m; ++j)
    for (int i = 1; i <= al[0]; ++i)
      if (j + al[i] <= m)
        dp[j + al[i]] = (1ll * cnt[al[i]] * dp[j] + dp[j + al[i]]) % mod;
  cout << dp[m] << endl;
  return 0;
}
