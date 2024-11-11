#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream &operator<<(ostream &str, pair<T, T> &a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream &operator>>(istream &str, pair<T, T> &a) {
  str >> a.first >> a.second;
  return str;
}
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(6);
  solve();
  return 0;
}
const long long MOD = 998244353, MAXN = 5e5 + 10, INF = 1e18 + 10, BASE = 37;
long long n, m;
vector<long long> a;
struct node {
  long long dp, dp1, dp2, dp12;
} t[MAXN * 4];
long long f(long long first) {
  if (first < 10) {
    return 0;
  }
  if (first >= 19) {
    return 0;
  }
  long long cnt = 0;
  for (long long i = 0; i <= min(first, 9ll); ++i) {
    long long s = first - i;
    if (s >= 0 && s <= 9) {
      cnt++;
    }
  }
  return cnt;
}
node merge(node l, node r, long long n1, long long n2) {
  node res;
  res.dp =
      (l.dp * r.dp % MOD + (f(n1 * 10 + n2) * l.dp2 % MOD) * r.dp1 % MOD) % MOD;
  res.dp1 =
      (l.dp1 * r.dp % MOD + (f(n1 * 10 + n2) * l.dp12 % MOD) * r.dp1 % MOD) %
      MOD;
  res.dp2 =
      (l.dp * r.dp2 % MOD + (f(n1 * 10 + n2) * l.dp2 % MOD) * r.dp12 % MOD) %
      MOD;
  res.dp12 =
      (l.dp1 * r.dp2 % MOD + (f(n1 * 10 + n2) * l.dp12 % MOD) * r.dp12 % MOD) %
      MOD;
  return res;
}
void build(long long v, long long tl, long long tr) {
  if (tl == tr) {
    t[v].dp = a[tl] + 1, t[v].dp1 = 1, t[v].dp2 = 1, t[v].dp12 = 1;
  } else {
    long long tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = merge(t[v * 2], t[v * 2 + 1], a[tm], a[tm + 1]);
  }
}
void upd(long long v, long long tl, long long tr, long long id, long long val) {
  if (tr < id || tl > id) {
    return;
  }
  if (tl == tr) {
    t[v].dp = val + 1;
    return;
  }
  long long tm = (tl + tr) / 2;
  upd(v * 2, tl, tm, id, val);
  upd(v * 2 + 1, tm + 1, tr, id, val);
  t[v] = merge(t[v * 2], t[v * 2 + 1], a[tm], a[tm + 1]);
}
void solve() {
  cin >> n >> m;
  a.resize(n);
  string s;
  cin >> s;
  for (long long i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  build(1, 0, n - 1);
  for (long long _ = 0; _ < m; ++_) {
    long long id, first;
    cin >> id >> first;
    id--;
    a[id] = first;
    upd(1, 0, n - 1, id, first);
    cout << t[1].dp << '\n';
  }
}
