#include <bits/stdc++.h>
using namespace std;
const int N(200010);
int n, nn, l, r;
int s[N];
struct SuffixArray {
  int m;
  int h[20][N];
  int cnt[N], sa[N], sa2[N], rank[N], rank2[N], log2[N];
  map<int, int> p;
  void radix_sort() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i != n; ++i) ++cnt[s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i != -1; --i) sa[--cnt[s[i]]] = i;
    for (int i = 1; i != n; ++i) {
      rank[sa[i]] = rank[sa[i - 1]];
      if (s[sa[i]] != s[sa[i - 1]]) ++rank[sa[i]];
    }
    for (int k = 1; rank[sa[n - 1]] != n - 1; k *= 2) {
      for (int i = 0; i != n; ++i) cnt[rank[sa[i]]] = i + 1;
      for (int i = n - 1; i != -1; --i)
        if (sa[i] >= k) sa2[--cnt[rank[sa[i] - k]]] = sa[i] - k;
      for (int i = n - k; i != n; ++i) sa2[--cnt[rank[i]]] = i;
      rank2[sa2[0]] = 0;
      for (int i = 1; i != n; ++i) {
        rank2[sa2[i]] = rank2[sa2[i - 1]];
        if (rank[sa2[i]] != rank[sa2[i - 1]] ||
            rank[sa2[i] + k] != rank[sa2[i - 1] + k])
          ++rank2[sa2[i]];
      }
      memcpy(sa, sa2, sizeof(sa2));
      memcpy(rank, rank2, sizeof(rank2));
    }
  }
  int lcp(int x, int y) {
    if (x == y) return n - x;
    x = rank[x];
    y = rank[y];
    if (x > y) swap(x, y);
    int t = log2[y - x];
    return min(h[t][x], h[t][y - (1 << t)]);
  }
  void build_lcp() {
    int k = 0;
    for (int i = 0; i != n; ++i)
      if (rank[i] == n - 1)
        h[0][rank[i]] = k = 0;
      else {
        if (k > 0) --k;
        int j = sa[rank[i] + 1];
        for (; s[i + k] == s[j + k]; ++k)
          ;
        h[0][rank[i]] = k;
      }
    for (int i = int(1); i < int(20); ++i)
      for (int j = int(0); j < int(n - (1 << i)); ++j)
        h[i][j] = min(h[i - 1][j], h[i - 1][j + (1 << (i - 1))]);
  }
  void init() {
    for (int i = int(2); i < int(N); ++i) log2[i] = log2[i / 2] + 1;
    scanf("%d", &n);
    nn = n;
    for (int i = int(0); i < int(n); ++i) scanf("%d", &s[i]);
    for (int i = n - 1; i; --i) {
      s[i] -= s[i - 1];
      s[i + n + 1] = -s[i];
    }
    s[n] = 1 << 30;
    n = 2 * n + 1;
    for (int i = int(0); i < int(n); ++i) p[s[i]] = 0;
    for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it)
      it->second = ++m;
    for (int i = int(0); i < int(n); ++i) s[i] = p[s[i]];
    s[n++] = 0;
    radix_sort();
    build_lcp();
  }
} SA;
int find1(int le, int ri, int v) {
  if (le == ri) return le;
  int mid = (le + ri) / 2;
  return SA.lcp(l + nn + 1, SA.sa[mid]) >= v ? find1(le, mid, v)
                                             : find1(mid + 1, ri, v);
}
int find2(int le, int ri, int v) {
  if (le == ri) {
    return le;
  }
  int mid = (le + ri + 1) / 2;
  return SA.lcp(l + nn + 1, SA.sa[mid]) >= v ? find2(mid, ri, v)
                                             : find2(le, mid - 1, v);
}
struct Query {
  int x, id;
  Query(int _x, int _id) : x(_x), id(_id) {}
};
vector<Query> qu[N];
int ans[N], c[N];
int low(int x) { return x & (-x); }
void add(int x) {
  for (; x <= n; x += low(x)) ++c[x];
}
int sum(int x) {
  int ret = 0;
  for (; x; x -= low(x)) ret += c[x];
  return ret;
}
int main() {
  int q;
  SA.init();
  scanf("%d", &q);
  for (int i = int(1); i < int(q + 1); ++i) {
    scanf("%d%d", &l, &r);
    int le = find1(0, SA.rank[l + nn + 1], r - l),
        ri = find2(SA.rank[l + nn + 1], n - 1, r - l) + 1;
    qu[nn].push_back(Query(ri, i));
    qu[nn].push_back(Query(le, -i));
    qu[max(0, 2 * l - r - 1)].push_back(Query(le, -i));
    qu[max(0, 2 * l - r - 1)].push_back(Query(ri, i));
    qu[r].push_back(Query(le, i));
    qu[r].push_back(Query(ri, -i));
  }
  for (int i = int(1); i < int(n + 1); ++i) {
    add(SA.rank[i] + 1);
    for (int j = int(0); j < int(qu[i].size()); ++j) {
      int t = qu[i][j].id < 0 ? -1 : 1;
      ans[t * qu[i][j].id] += t * sum(qu[i][j].x);
    }
  }
  for (int i = int(1); i < int(q + 1); ++i) printf("%d\n", ans[i]);
  return 0;
}
