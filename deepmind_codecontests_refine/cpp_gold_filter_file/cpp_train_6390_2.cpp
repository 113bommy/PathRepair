#include <bits/stdc++.h>
#pragma GCC optimize("trapv")
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &out, const pair<T, V> x) {
  out << "{" << x.first << " : " << x.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const set<T> x) {
  for (auto &it : x) {
    out << it << " ";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const multiset<T> x) {
  for (auto &it : x) {
    out << it << " ";
  }
  return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, const map<T, V> x) {
  for (auto &it : x) {
    out << "[" << it.first << "]"
        << " = " << it.second << "\n";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> x) {
  for (int i = 0; i < x.size() - 1; ++i) {
    out << x[i] << " ";
  }
  out << x.back();
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<vector<T> > x) {
  for (int i = 0; i < x.size() - 1; ++i) {
    out << "[" << i << "]"
        << " = {" << x[i] << "}\n";
  }
  out << "[" << x.size() - 1 << "]"
      << " = {" << x.back() << "}\n";
  return out;
}
const long long N = 2e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
long long cnt[N], sum[N], mx[N], mn[N], dp[N];
long long pw[N];
long long add(long long x, long long y) { return (x + y) % MOD; }
long long sub(long long x, long long y) {
  return (x % MOD - y % MOD + MOD) % MOD;
}
long long mult(long long x, long long y) {
  x %= MOD;
  y %= MOD;
  return (x * y) % MOD;
}
struct node {
  long long cnt, sum, mx, mn, dp, i;
  node() { cnt = sum = mx = mn = dp = i = 0; }
};
node merge(node a, node b, long long mn) {
  node ret;
  ret.i = a.i + 1;
  long long i = ret.i;
  ret.cnt = add(a.cnt + b.cnt, 1);
  ret.mn = add(mult(mult(4, pw[i - 1]), mn), a.mn);
  ret.mx = add(mult(mult(7, pw[i - 1]), mn), b.mx);
  long long l, r, x;
  l = add(mult(mult(mult(4, pw[i - 1]), mn), a.cnt * 2), a.sum);
  r = add(mult(mult(mult(7, pw[i - 1]), mn), b.cnt * 2), b.sum);
  ret.sum = add(add(l, add(mult(mult(4, pw[i - 1]), mn), a.mx)),
                add(r, add(mult(mult(7, pw[i - 1]), mn), b.mn)));
  x = mult(4, pw[i - 1] * mn);
  l = a.dp + mult(mult(x, x), a.cnt) + mult(x, a.sum);
  x = mult(7, pw[i - 1] * mn);
  r = b.dp + mult(mult(x, x), b.cnt) + mult(x, b.sum);
  ret.dp = add(l + r, mult(add(mult(mult(4, pw[i - 1]), mn), a.mx),
                           add(mult(mult(7, pw[i - 1]), mn), b.mn)));
  return ret;
}
node tmp[N];
string l, r;
string x;
node get(long long id, long long h) {
  if (h == 0) return tmp[0];
  node ret = get(id + 1, h - 1);
  long long t = x[id] - '0';
  if (t != 4) return merge(tmp[h - 1], ret, 1);
  long long i = ret.i + 1;
  ret.i = i;
  ret.mn = add(t * pw[i - 1], ret.mn);
  ret.mx = add(t * pw[i - 1], ret.mx);
  long long x;
  x = mult(t, pw[i - 1]);
  ret.dp = add(ret.dp + mult(mult(x, x), ret.cnt) + mult(x, ret.sum), 0);
  ret.sum = add(mult(t * pw[i - 1], ret.cnt * 2), ret.sum);
  if (t == 4) return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> l >> r;
  pw[0] = 1;
  for (long long i = 1; i < N; ++i) pw[i] = (pw[i - 1] * 10LL) % MOD;
  for (long long i = 1; i < N; ++i) {
    tmp[i] = merge(tmp[i - 1], tmp[i - 1], 1);
  }
  long long ans;
  x = r;
  ans = get(0, x.size()).dp;
  x = l;
  ans = (ans % MOD - get(0, x.size()).dp % MOD + MOD) % MOD;
  cout << ans;
  return 0;
}
