#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, m;
bitset<100> s[101];
vector<long long> e[101];
bool vis[100];
set<long long> c;
bitset<100> curb;
unordered_set<bitset<100>> found;
bool skip[100];
long long countt;
long long fac[101];
vector<set<long long>> comp;
vector<bitset<100>> compb;
vector<vector<long long>> f;
void dfs(long long u) {
  if (vis[u]) return;
  vis[u] = true;
  c.insert(u);
  curb |= s[u];
  for (long long v : e[u]) dfs(v);
}
void dfs2(long long u, long long i, long long ex) {
  if (vis[u] || comp[i].count(u) == 0) return;
  vis[u] = true;
  countt++;
  for (long long v : e[u])
    if (v != ex) dfs2(v, i, ex);
}
void bad(long long i) {
  cout << "0\n";
  exit(0);
}
void _calc(long long i, vector<bitset<100>> &e, bitset<100> &b) {
  if (comp[i].size() == 1) {
    e.push_back(s[*comp[i].begin()]);
    b = e[0];
    comp[i].clear();
    return;
  }
  for (long long a : comp[i]) {
    for (long long x : comp[i]) vis[x] = false;
    countt = 0;
    auto it = comp[i].begin();
    if (*it == a) ++it;
    dfs2(*it, i, a);
    if (countt != (long long)comp[i].size() - 1) continue;
    comp[i].erase(a);
    _calc(i, e, b);
    long long l = -1, r = -1;
    for (long long j = 0; j < (long long)e.size(); ++j) {
      if ((s[a] & e[j]).count() && (s[a] | e[j]) != s[a]) {
        if (l == -1)
          l = j;
        else if (r == -1)
          r = j;
        else
          bad(1);
      }
    }
    if (r != -1) {
      if ((s[a] | b) != b) bad(2);
      for (long long j = 0; j < (long long)e.size(); ++j) {
        if (j < l || j > r) {
          if ((e[j] & s[a]).count()) bad(3);
        } else if (j > l && j < r) {
          if ((e[j] | s[a]) != s[a]) bad(4);
        }
      }
      bitset<100> x = e[r] & s[a];
      bitset<100> y = e[r] ^ x;
      e.insert(e.begin() + r + 1, y);
      e[r] = x;
      x = e[l] & s[a];
      y = e[l] ^ x;
      e.insert(e.begin() + l + 1, x);
      e[l] = y;
      b |= s[a];
      return;
    }
    if (l == -1) {
      long long l1 = 0, l2 = (long long)e.size() - 1;
      while (l1 < (long long)e.size() && (e[l1] & s[a]).count() == 0) l1++;
      while (l2 >= 0 && (e[l2] & s[a]).count() == 0) l2--;
      for (long long j = l1 + 1; j < l2; ++j)
        if ((e[j] & s[a]).count() == 0) bad(5);
      assert(l1 <= l2 && (l1 > 0 || l2 < (long long)e.size() - 1));
      if ((s[a] | b) == b) return;
      if (l1 == 0)
        e.insert(e.begin(), s[a] ^ (s[a] & b));
      else if (l2 == (long long)e.size() - 1)
        e.push_back(s[a] ^ (s[a] & b));
      else
        bad(6);
      b |= s[a];
      return;
    }
    long long l1 = l, l2 = l;
    while (l1 > 0 && (e[l1 - 1] | s[a]) == s[a]) l1--;
    while (l2 < (long long)e.size() - 1 && (e[l2 + 1] | s[a]) == s[a]) l2++;
    if (l1 != l && l2 != l) bad(7);
    if ((s[a] | b) != b && l1 > 0 && l2 < (long long)e.size() - 1) bad(8);
    for (long long j = 0; j < l1; ++j)
      if ((e[j] & s[a]).count()) bad(9);
    for (long long j = l2 + 1; j < (long long)e.size(); ++j)
      if ((e[j] & s[a]).count()) bad(10);
    assert(l1 != l || l2 != l || (s[a] | b) != b);
    bitset<100> x = e[l] & s[a];
    bitset<100> y = e[l] ^ x;
    if (l1 != l || (l1 == 0 && l2 == 0)) {
      e.insert(e.begin() + l + 1, y);
      e[l] = x;
      if ((s[a] | b) != b) e.insert(e.begin(), s[a] ^ (s[a] & b));
    } else {
      e[l] = y;
      e.insert(e.begin() + l + 1, x);
      if ((s[a] | b) != b) e.push_back(s[a] ^ (s[a] & b));
    }
    b |= s[a];
    return;
  }
}
long long calc(long long i) {
  vector<bitset<100>> e;
  bitset<100> b;
  _calc(i, e, b);
  long long res = 1;
  for (auto g : e) {
    long long r = g.count();
    for (long long j : f[i])
      if ((compb[j] & g) == compb[j]) {
        r -= compb[j].count() - 1;
      }
    res = (res * fac[r]) % mod;
  }
  if (e.size() > 1) res = (res * 2) % mod;
  return res;
}
int32_t main() {
  fac[0] = 1;
  for (long long i = 1; i <= 100; ++i) fac[i] = (fac[i - 1] * i) % mod;
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long q;
    cin >> q;
    for (long long j = 0; j < q; ++j) {
      long long x;
      cin >> x;
      x--;
      s[i].set(x);
    }
  }
  for (long long i = 0; i < n; ++i) s[m].set(i);
  m++;
  for (long long i = m - 1; i >= 0; --i) {
    if (found.count(s[i])) {
      skip[i] = true;
      continue;
    }
    found.insert(s[i]);
  }
  for (long long i = 0; i < m; ++i)
    for (long long j = i + 1; j < m; ++j)
      if (!skip[i] && !skip[j]) {
        bitset<100> b = s[i] & s[j];
        if (b.count() == 0 || b == s[i] || b == s[j]) continue;
        e[i].push_back(j);
        e[j].push_back(i);
      }
  for (long long i = 0; i < m; ++i)
    if (!skip[i]) {
      if (vis[i]) continue;
      c.clear();
      curb.reset();
      dfs(i);
      comp.push_back(c);
      compb.push_back(curb);
      f.emplace_back();
    }
  for (long long i = 0; i < (long long)comp.size(); ++i) {
    long long k = -1;
    for (long long j = 0; j < (long long)comp.size(); ++j)
      if (i != j) {
        if (((compb[i] & compb[j]) == compb[i] &&
             (compb[i] != compb[j] || comp[j].size() == 1)) &&
            (k == -1 || compb[j].count() < compb[k].count() ||
             (compb[j].count() == compb[k].count() && comp[k].size() > 1))) {
          k = j;
        }
      }
    if (k != -1) f[k].push_back(i);
  }
  long long res = 1;
  for (long long i = 0; i < (long long)comp.size(); ++i)
    res = (res * calc(i)) % mod;
  cout << res << "\n";
}
