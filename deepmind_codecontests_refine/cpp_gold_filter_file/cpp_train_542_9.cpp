#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = mod * mod;
const long double eps = 1e-12;
const long double pi = acos(-1.0);
long long mod_pow(long long a, long long n, long long m = mod) {
  a %= m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint &a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint &a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct SegT {
 private:
  int sz;
  vector<pair<int, int>> node;
  pair<int, int> init_c = {-mod, -1};
  function<pair<int, int>(pair<int, int>, pair<int, int>)> f;

 public:
  SegT(vector<int> ori,
       function<pair<int, int>(pair<int, int>, pair<int, int>)> _f,
       pair<int, int> _init_c) {
    f = _f;
    init_c = _init_c;
    int n = ori.size();
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(2 * sz - 1, init_c);
    for (int i = 0; i < n; i++) {
      node[i + sz - 1] = {ori[i], i};
    }
    for (int i = sz - 1 - 1; i >= 0; i--) {
      node[i] = f(node[2 * i + 1], node[2 * i + 2]);
    }
  }
  pair<int, int> query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = sz;
    if (r <= a || b <= l)
      return init_c;
    else if (a <= l && r <= b)
      return node[k];
    else {
      pair<int, int> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      pair<int, int> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
};
struct range_tree {
 private:
  int sz = 1;
  vector<vector<int>> node;

 public:
  range_tree(vector<int> v) {
    int n = v.size();
    while (sz < n) sz *= 2;
    node.resize(sz * 2 - 1);
    for (int i = 0; i < n; i++) {
      node[i + sz - 1].push_back(v[i]);
    }
    for (int i = sz - 1 - 1; i >= 0; i--) {
      node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
    }
  }
  vector<int> merge(vector<int> a, vector<int> b) {
    int id1 = 0, id2 = 0;
    vector<int> res;
    while (id1 < a.size() || id2 < b.size()) {
      int mi = 1000000007;
      if (id1 < a.size()) mi = min(mi, a[id1]);
      if (id2 < b.size()) mi = min(mi, b[id2]);
      while (id1 < a.size() && mi == a[id1]) {
        res.push_back(a[id1]);
        id1++;
      }
      while (id2 < b.size() && mi == b[id2]) {
        res.push_back(b[id2]);
        id2++;
      }
    }
    return res;
  }
  int qloc(int s, int a, int b) {
    s += sz - 1;
    while (s > 0) {
      int pre = s;
      s = (s - 1) / 2;
      if (2 * s + 1 == pre) {
        int cnt =
            lower_bound((node[2 * s + 2]).begin(), (node[2 * s + 2]).end(), b) -
            upper_bound((node[2 * s + 2]).begin(), (node[2 * s + 2]).end(), a);
        if (cnt > 0) {
          s = 2 * s + 2;
          break;
        }
      }
    }
    if (s == 0) return sz;
    while (s < sz - 1) {
      int cnt =
          lower_bound((node[2 * s + 1]).begin(), (node[2 * s + 1]).end(), b) -
          upper_bound((node[2 * s + 1]).begin(), (node[2 * s + 1]).end(), a);
      if (cnt > 0) {
        s = 2 * s + 1;
      } else {
        s = 2 * s + 2;
      }
    }
    return s - (sz - 1);
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> up(n), dow(n);
  up[n - 1] = n - 1, dow[n - 1] = n - 1;
  for (int i = n - 1 - 1; i >= 0; i--) {
    up[i] = i, dow[i] = i;
    if (a[i] <= a[i + 1]) {
      up[i] = up[i + 1];
    }
    if (a[i] >= a[i + 1]) {
      dow[i] = dow[i + 1];
    }
  }
  vector<int> fup(n), fdow(n);
  {
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && st.top().first < a[i]) {
        fup[st.top().second] = i;
        st.pop();
      }
      st.push({a[i], i});
    }
    while (!st.empty()) {
      fup[st.top().second] = n;
      st.pop();
    }
  }
  {
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && st.top().first > a[i]) {
        fdow[st.top().second] = i;
        st.pop();
      }
      st.push({a[i], i});
    }
    while (!st.empty()) {
      fdow[st.top().second] = n;
      st.pop();
    }
  }
  SegT stma(a, [&](pair<int, int> a, pair<int, int> b) { return max(a, b); },
            {-mod, -1});
  SegT stmi(a, [&](pair<int, int> a, pair<int, int> b) { return min(a, b); },
            {mod, -1});
  range_tree rt(a);
  vector<int> ri3(n), ri4(n);
  vector<vector<int>> memo3(n), memo4(n);
  for (int i = 0; i < n; i++) {
    int uid = fup[i];
    int did = fdow[i];
    ri3[i] = ri4[i] = n;
    if (uid == n && did == n) {
      continue;
    }
    if (did < uid) {
      int tdid = dow[did];
      if (tdid + 1 < n) {
        ri3[i] = tdid + 1;
        memo3[i] = {i, tdid, tdid + 1};
      }
      if (uid < n) {
        int tuid = up[uid];
        pair<int, int> pmi = stmi.query(i + 1, tuid);
        int mi = pmi.first;
        int ma = a[tuid];
        int las = rt.qloc(tuid, mi, ma);
        if (las < n) {
          ri4[i] = las;
          memo4[i] = {i, pmi.second, tuid, las};
        }
      }
    } else {
      int tuid = up[uid];
      if (tuid + 1 < n) {
        ri3[i] = tuid + 1;
        memo3[i] = {i, tuid, tuid + 1};
      }
      if (did < n) {
        int tdid = dow[did];
        pair<int, int> pma = stma.query(i + 1, tdid);
        int ma = pma.first;
        int mi = a[tdid];
        int las = rt.qloc(tdid, mi, ma);
        if (las < n) {
          ri4[i] = las;
          memo4[i] = {i, pma.second, tdid, las};
        }
      }
    }
  }
  vector<vector<pair<int, int>>> querys(n);
  for (int aa = 0; aa < q; aa++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    querys[l].push_back({r, aa});
  }
  vector<int> ans(q);
  vector<vector<int>> sans(q);
  int mir3 = n, mir4 = n;
  vector<int> mem3, mem4;
  for (int i = n - 1; i >= 0; i--) {
    if (ri3[i] < mir3) {
      mir3 = ri3[i];
      mem3 = memo3[i];
    }
    if (ri4[i] < mir4) {
      mir4 = ri4[i];
      mem4 = memo4[i];
    }
    for (pair<int, int> p : querys[i]) {
      int id = p.second;
      if (p.first >= mir4) {
        ans[id] = 4;
        sans[id] = mem4;
      } else if (p.first >= mir3) {
        ans[id] = 3;
        sans[id] = mem3;
      } else {
        ans[id] = 0;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
    for (int j = 0; j < sans[i].size(); j++) {
      if (j > 0) cout << " ";
      cout << sans[i][j] + 1;
    }
    cout << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  char nyaa;
  cin >> nyaa;
  return 0;
}
