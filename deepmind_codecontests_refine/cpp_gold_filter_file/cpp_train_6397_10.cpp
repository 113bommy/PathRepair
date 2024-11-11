#include <bits/stdc++.h>
using namespace std;
struct SuffixArray {
  vector<int> a, lcp;
  string s;
  int n;
  SuffixArray(const string &s) : s(s) {
    n = s.size();
    calcSuffixArray();
    calcLCP();
  }
  void calcSuffixArray() {
    vector<int> b(n), key(n), cnt(max(n, 128));
    vector<bool> mark(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) ++cnt[(int)s[i]];
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for (int i = n - 1; i >= 0; --i) a[--cnt[(int)s[i]]] = i;
    for (int i = 0; i < n; ++i) mark[i] = i == 0 || s[a[i]] != s[a[i - 1]];
    for (int k = 1; k < n; k <<= 1) {
      int nkeys = 0;
      for (int i = 0; i < n; ++i) {
        if (mark[i]) ++nkeys;
        key[a[i]] = nkeys - 1;
        b[i] = (a[i] - k + n) % n;
      }
      if (nkeys == n) break;
      fill(cnt.begin(), cnt.end(), 0);
      for (int i = 0; i < n; ++i) ++cnt[key[b[i]]];
      partial_sum(cnt.begin(), cnt.end(), cnt.begin());
      for (int i = n - 1; i >= 0; --i) a[--cnt[key[b[i]]]] = b[i];
      for (int i = 0, kv = -1; i < n; ++i) {
        int j = (a[i] + k) % n;
        if (key[j] != kv) {
          mark[i] = true;
          kv = key[j];
        }
      }
    }
  }
  void calcLCP() {
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[a[i]] = i;
    lcp.resize(n);
    lcp[0] = 0;
    for (int i = 0, q = 0; i + 1 < n; ++i) {
      int j = a[rank[i] - 1];
      while (s[i + q] == s[j + q]) ++q;
      lcp[rank[i]] = q;
      if (q > 0) --q;
    }
  }
};
struct DisjointSet {
  static const int MODULO = (int)1e9 + 7;
  vector<int> a;
  vector<int> b;
  vector<int> c;
  vector<int> lab;
  int res;
  DisjointSet(int n) : a(n), b(n), c(n), lab(n, -1), res(0) {}
  int get(int u) { return lab[u] < 0 ? u : lab[u] = get(lab[u]); }
  void join(int u, int v) {
    u = get(u);
    v = get(v);
    assert(u != v);
    if (lab[u] < lab[v]) swap(u, v);
    res = (res - 1LL * a[u] * b[u] * c[u]) % MODULO;
    res = (res - 1LL * a[v] * b[v] * c[v]) % MODULO;
    a[v] += a[u];
    b[v] += b[u];
    c[v] += c[u];
    lab[v] += lab[u];
    lab[u] = v;
    res = (res + 1LL * a[v] * b[v] * c[v]) % MODULO;
    if (res < 0) res += MODULO;
  }
};
int main() {
  ios::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b >> c;
  string s = a + (char)('z' + 1) + b + (char)('z' + 2) + c + (char)('a' - 1);
  SuffixArray sa(s);
  int n = s.size();
  DisjointSet ds(n);
  for (int i = 0; i < n; ++i) {
    if (sa.a[i] <= (int)a.size())
      ds.a[i] = 1;
    else if (sa.a[i] <= (int)a.size() + 1 + (int)b.size())
      ds.b[i] = 1;
    else
      ds.c[i] = 1;
  }
  vector<pair<int, int> > v(n);
  for (int i = 1; i < n; ++i) v[i] = make_pair(sa.lcp[i], i);
  int m = min(min(a.size(), b.size()), c.size());
  vector<int> res(m);
  sort(v.begin(), v.end());
  for (int len = m, p = (int)v.size() - 1; len >= 1; --len) {
    while (p >= 0 && v[p].first >= len) {
      ds.join(v[p].second - 1, v[p].second);
      --p;
    }
    res[len - 1] = ds.res;
  }
  for (int i = 0; i < m; ++i) printf("%d ", res[i]);
  return 0;
}
