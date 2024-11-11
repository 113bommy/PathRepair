#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;
const ld EPS = 1e-9;
const ll MOD = 998244353;
const ld PI = 3.141592653589793;
const int maxn = 1e5 + 1;
ll a[maxn];
string take_x(string fi, string se) {
  string res;
  for (int i = 0; i < fi.size(); ++i) {
    if (fi[i] == se[i]) {
      res += '0';
    } else {
      res += '1';
    }
  }
  return res;
}
bool is_dist_1(string s, int k) {
  int cnt_ones = count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
  if (cnt_ones != k) {
    return false;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      int cnt = 0;
      while (i < s.size() && s[i] == '1') {
        ++i;
        ++cnt;
      }
      return cnt_ones == cnt;
    }
  }
  return false;
}
struct node {
  int max_len[2];
  int cnt[2];
  int pref[2];
  int suff[2];
};
node merge(node fi, node se) {
  node res;
  for (int i = 0; i < 2; ++i) {
    res.max_len[i] = max(fi.max_len[i], se.max_len[i]);
    res.max_len[i] = max(res.max_len[i], fi.suff[i] + se.pref[i]);
    res.suff[i] = se.suff[i];
    if (se.cnt[i ^ 1] == 0) {
      res.suff[i] = se.suff[i] + fi.suff[i];
    }
    res.pref[i] = fi.pref[i];
    if (fi.pref[i ^ 1] == 0) {
      res.pref[i] = fi.pref[i] + se.pref[i];
    }
    res.cnt[i] = fi.cnt[i] + se.cnt[i];
  }
  return res;
}
node t[4 * maxn];
int to_push[4 * maxn];
node zero = {{1, 0}, {1, 0}, {1, 0}, {1, 0}};
node one = {{0, 1}, {0, 1}, {0, 1}, {0, 1}};
string s;
void build(int v, int tl, int tr) {
  to_push[v] = 0;
  if (tl == tr - 1) {
    t[v] = s[tl] == '0' ? zero : one;
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm, tr);
  t[v] = merge(t[v << 1], t[v << 1 | 1]);
}
void upd(int v) {
  to_push[v] ^= 1;
  swap(t[v].max_len[0], t[v].max_len[1]);
  swap(t[v].cnt[0], t[v].cnt[1]);
  swap(t[v].pref[0], t[v].pref[1]);
  swap(t[v].suff[0], t[v].suff[1]);
}
void push(int v) {
  if (to_push[v]) {
    to_push[v] = 0;
    upd(v << 1);
    upd(v << 1 | 1);
  }
}
void xor_seg(int v, int tl, int tr, int l, int r) {
  if (tl >= r || l >= tr) {
    return;
  }
  if (tl >= l && tr <= r) {
    upd(v);
    return;
  }
  int tm = (tl + tr) >> 1;
  push(v);
  xor_seg(v << 1, tl, tm, l, r);
  xor_seg(v << 1 | 1, tm, tr, l, r);
  t[v] = merge(t[v << 1], t[v << 1 | 1]);
}
bool can[maxn];
ll x[maxn];
ll y[maxn];
ll fwt[2][maxn];
void fwt_add(int tp, int pos, int val) {
  for (; pos < maxn; pos |= (pos + 1)) {
    fwt[tp][pos] += val;
  }
}
ll fwt_get(int tp, int pos) {
  ll res = 0;
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
    res += fwt[tp][pos];
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ps;
  vector<int> xx;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    cin >> y[i];
    xx.push_back(x[i]);
  }
  sort(xx.begin(), xx.end());
  xx.erase(unique(xx.begin(), xx.end()), xx.end());
  for (int i = 1; i <= n; ++i) {
    x[i] = lower_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
    fwt_add(0, x[i], 1);
    int cur = fwt_get(0, x[i]) - fwt_get(0, x[i] - 1);
    if (cur == 1) {
      fwt_add(1, x[i], 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ps.emplace_back(y[i], x[i]);
  }
  sort(ps.begin(), ps.end());
  ll ans = 0;
  for (int i = 0; i < ps.size();) {
    int cur_y = ps[i].first;
    int j = i;
    while (j < ps.size() && ps[j].first == cur_y) {
      ++j;
    }
    for (int e = i; e < j; ++e) {
      ll left = fwt_get(1, ps[e].second);
      int rr = (e == j - 1 ? maxn - 1 : ps[e + 1].second - 1);
      ll right = fwt_get(1, rr) - fwt_get(1, ps[e].second - 1);
      ans += right * left;
    }
    for (int e = i; e < j; ++e) {
      fwt_add(0, ps[e].second, -1);
      int cur = fwt_get(0, ps[e].second) - fwt_get(0, ps[e].second - 1);
      if (!cur) {
        fwt_add(1, ps[e].second, -1);
      }
    }
    i = j;
  }
  cout << ans;
}
