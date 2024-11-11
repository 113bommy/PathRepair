#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> sa;
vector<long long> sort_cyclic_shifts(string const& s) {
  long long n = s.size();
  const long long alphabet = 256;
  vector<long long> p(n), c(n), cnt(max(alphabet, n), 0);
  for (long long i = 0; i < n; i++) cnt[s[i]]++;
  for (long long i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
  for (long long i = 0; i < n; i++) p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  long long classes = 1;
  for (long long i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) classes++;
    c[p[i]] = classes - 1;
  }
  vector<long long> pn(n), cn(n);
  for (long long h = 0; (1 << h) < n; ++h) {
    for (long long i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for (long long i = 0; i < n; i++) cnt[c[pn[i]]]++;
    for (long long i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
    for (long long i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (long long i = 1; i < n; i++) {
      pair<long long, long long> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<long long, long long> prev = {c[p[i - 1]],
                                         c[(p[i - 1] + (1 << h)) % n]};
      if (cur != prev) ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}
string ss;
void create(string& s) {
  ss = s;
  s += '$';
  sa = sort_cyclic_shifts(s);
  sa.erase(sa.begin());
}
vector<long long> lcp_construction(string const& s,
                                   vector<long long> const& p) {
  long long n = s.size();
  vector<long long> rank(n, 0);
  for (long long i = 0; i < n; i++) rank[p[i]] = i;
  long long k = 0;
  vector<long long> lcp(n - 1, 0);
  for (long long i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    long long j = p[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return lcp;
}
const long long N = 1e5 + 10;
const long long LN = 17;
long long lg[N];
long long sp[LN][N];
long long get(long long l, long long r) {
  if (l > r) swap(l, r);
  if (l == r) return n - sa[l];
  r--;
  long long p = lg[r - l + 1];
  return min(sp[p][l], sp[p][r - (1 << p) + 1]);
}
long long find(long long i, long long j) {
  long long res = 0;
  for (long long k = 0; k < n; k++) {
    long long gg = get(k, i);
    if (gg >= j)
      res += j;
    else if (k < i)
      res += n - sa[k];
    else
      res += gg;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  n = s.length();
  create(s);
  vector<long long> lcp = lcp_construction(ss, sa);
  for (long long i = 2; i <= n; i++) lg[i] = (lg[i - 1] + !(i & (i - 1)));
  for (long long i = 0; i < n - 1; i++) sp[0][i] = lcp[i];
  for (long long i = 1; i < LN; i++)
    for (long long j = 0; j < n - 1; j++)
      if (j + (1LL << (i - 1)) < n - 1)
        sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1LL << (i - 1))]);
  long long l = 0;
  long long r = n - 1;
  long long res = -1;
  long long k;
  cin >> k;
  if ((n * (n + 1)) / 2 < k) {
    cout << "No such line";
    exit(0);
  }
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (find(mid, n - sa[mid]) < k) {
      l = mid + 1;
    } else {
      res = mid;
      r = mid - 1;
    }
  }
  l = 1;
  r = n - sa[res];
  long long res2 = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (find(res, mid) < k) {
      l = mid + 1;
    } else {
      res2 = mid;
      r = mid - 1;
    }
  }
  for (long long i = 0; i < res2; i++) cout << ss[sa[res] + i];
}
