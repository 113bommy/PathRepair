#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, B = 50;
int lcp[N];
struct event {
  int l, r;
  string s;
  event() {}
  event(int l, int r) : l(l), r(r), s("") {}
  event(int x, string s) : l(x), r(x), s(s) {}
};
void make_lcp(int &j, string &a, string &b) {
  for (j = 0; j < (int)min(a.length(), b.length()) && a[j] == b[j]; ++j)
    ;
}
struct node {
  int l, r, res, len;
};
node tree[N * 4];
node operator+(const node &a, const node &b) {
  return (node){a.l == a.len ? a.l + b.l : a.l, b.r == b.len ? b.r + a.r : b.r,
                max(max(a.res, b.res), a.r + b.l), a.len + b.len};
}
int LIM, ans[N], T[4 * N], len[N];
void update(int x, int l, int r, int p) {
  if (l == r) {
    int v = lcp[l] >= ::LIM;
    tree[x] = (node){v, v, v, 1};
    T[x] = len[l];
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid)
    update(x + x, l, mid, p);
  else
    update(x + x + 1, mid + 1, r, p);
  tree[x] = tree[x + x] + tree[x + x + 1];
  T[x] = max(T[x + x], T[x + x + 1]);
}
node query(int x, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return tree[x];
  int mid = (l + r) / 2;
  if (qr <= mid) return query(x + x, l, mid, ql, qr);
  if (ql > mid) return query(x + x + 1, mid + 1, r, ql, qr);
  return query(x + x, l, mid, ql, qr) + query(x + x + 1, mid + 1, r, ql, qr);
}
int query_len(int x, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) return T[x];
  int mid = (l + r) / 2;
  return max(query_len(x + x, l, mid, ql, qr),
             query_len(x + x + 1, mid + 1, r, ql, qr));
}
void build(int x, int l, int r) {
  if (l == r) {
    int v = lcp[l] >= ::LIM;
    tree[x] = (node){v, v, v, 1};
    T[x] = len[l];
    return;
  }
  int mid = (l + r) / 2;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  tree[x] = tree[x + x] + tree[x + x + 1];
  T[x] = max(T[x + x], T[x + x + 1]);
}
void work(int len, vector<string> S, vector<event> &Q) {
  ::LIM = len;
  int n = (int)S.size();
  for (int i = 0; i < n; ++i) ::len[i] = (int)S[i].length();
  for (int i = 1; i < n; ++i) make_lcp(lcp[i], S[i], S[i - 1]);
  build(1, 0, n - 1);
  int cnt = 0;
  for (event e : Q) {
    if (e.s.empty()) {
      int l = e.l, r = e.r;
      --l, --r;
      int res = (l == r ? 0 : query(1, 0, n - 1, l + 1, r).res);
      if (res) ans[cnt] = max(ans[cnt], len * (res + 1));
      ans[cnt] = max(ans[cnt], query_len(1, 0, n - 1, l, r));
      cnt++;
    } else {
      int i = e.l;
      --i;
      S[i] = e.s;
      if (i) make_lcp(lcp[i], S[i], S[i - 1]);
      if (i < n - 1) make_lcp(lcp[i + 1], S[i + 1], S[i]);
      ::len[i] = (int)S[i].length();
      update(1, 0, n - 1, i);
      if (i < n - 1) update(1, 0, n - 1, i + 1);
    }
  }
}
int solve(const vector<int> &a) {
  vector<pair<int, int>> q;
  q.push_back({0, -1});
  int res = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    while (q.back().first >= a[i]) {
      res = max(res, q.back().first * (i - q[(int)q.size() - 2].second));
      q.pop_back();
    }
    q.push_back({a[i], i});
  }
  while (q.back().first > 0) {
    res = max(res,
              q.back().first * ((int)a.size() - q[(int)q.size() - 2].second));
    q.pop_back();
  }
  return res;
}
int debug = 0;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  if (debug)
    n = m = 100000;
  else
    cin >> n >> m;
  vector<string> ss;
  for (int i = 1; i <= n; ++i) {
    string s;
    if (debug)
      s = rand() % 26 + 'a';
    else
      cin >> s;
    ss.push_back(s);
  }
  vector<event> all;
  for (int i = 0; i < m; ++i) {
    int type;
    if (debug)
      type = 1;
    else
      cin >> type;
    if (type == 2) {
      int x;
      string s;
      cin >> x >> s;
      all.push_back(event(x, s));
    } else {
      int l, r;
      if (debug) {
        l = rand() % n + 1, r = rand() % n + 1;
        if (l > r) swap(l, r);
      } else
        cin >> l >> r;
      all.push_back(event(l, r));
    }
  }
  for (int len = 2; len < B; ++len) work(len, ss, all);
  set<pair<int, int>> big;
  for (int i = 1; i < n; ++i) make_lcp(lcp[i], ss[i], ss[i - 1]);
  for (int i = 1; i < n; ++i)
    if (lcp[i] >= B) big.insert({i, lcp[i]});
  int cnt = 0;
  for (event e : all) {
    if (e.s.empty()) {
      int l = e.l, r = e.r;
      --l, --r;
      vector<int> tmp;
      int las = -3;
      for (auto it = big.lower_bound({l + 1, 0});
           it != big.end() && it->first <= r; ++it) {
        auto x = *it;
        if (x.first > l && x.first <= r) {
          if (tmp.empty() || las + 1 == x.first) {
            tmp.push_back(x.second);
          } else {
            ans[cnt] = max(ans[cnt], solve(tmp));
            tmp.clear();
            tmp.push_back(x.second);
          }
          las = x.first;
        }
      }
      if (!tmp.empty()) ans[cnt] = max(ans[cnt], solve(tmp));
      cnt++;
    } else {
      int i = e.l;
      --i;
      ss[i] = e.s;
      int ol = lcp[i], ol2 = lcp[i + 1];
      if (i) make_lcp(lcp[i], ss[i], ss[i - 1]);
      if (i < n - 1) make_lcp(lcp[i + 1], ss[i + 1], ss[i]);
      int ne = lcp[i], ne2 = lcp[i + 1];
      if (i) {
        if (ol >= B) big.erase({i, ol});
        if (ne >= B) big.insert({i, ne});
      }
      if (i < n - 1) {
        if (ol2 >= B) big.erase({i + 1, ol2});
        if (ne2 >= B) big.insert({i + 1, ne2});
      }
    }
  }
  if (!debug)
    for (int i = 0; i < cnt; ++i) printf("%d\n", ans[i]);
}
