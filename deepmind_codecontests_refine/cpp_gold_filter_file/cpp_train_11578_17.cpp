#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
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
const long long INF = 1e18, MAXN = 3e5 + 10;
long long m, n, k, t;
bool check(long long val, vector<vector<long long>> &sg) {
  long long T = 0;
  vector<long long> ps(n + 2);
  for (auto it : sg) {
    if (it[2] > val) {
      ps[it[1] + 1] -= 1;
      ps[it[0]] += 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    ps[i] = ps[i - 1] + ps[i];
  }
  long long cnt = 0;
  for (long long i = 0; i <= n; ++i) {
    if (ps[i] != 0) {
      cnt++;
    }
  }
  T = n + cnt * 2 + 1;
  if (T <= t) {
    return true;
  } else {
    return false;
  }
}
void solve() {
  cin >> m >> n >> k >> t;
  vector<long long> a(m + 1);
  for (long long i = 1; i <= m; ++i) {
    cin >> a[i];
  }
  a[0] = INF;
  sort((a).rbegin(), (a).rend());
  vector<vector<long long>> sg;
  for (long long i = 0; i < k; ++i) {
    long long cl, cr, d;
    cin >> cl >> cr >> d;
    sg.push_back({cl, cr, d});
  }
  long long L = 0, R = m + 1;
  while (R - L > 1) {
    long long mid = (R + L) / 2;
    long long val = a[mid];
    if (check(val, sg)) {
      L = mid;
    } else {
      R = mid;
    }
  }
  cout << (L) << '\n';
  ;
}
