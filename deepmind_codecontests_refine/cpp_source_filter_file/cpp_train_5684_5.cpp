#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<vector<T>>& v) {
  for (auto& x : v) out << x << '\n';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto x : v) out << x << ' ';
  return out;
}
const long long inf = 1e18, N = 2e5 + 10;
vector<long long> v(N), c(N);
multiset<long long> second[4];
multiset<long long>::iterator it[4];
long long ptr[4];
long long num[4];
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k > m) {
    cout << -1;
    exit(0);
  }
  long long cur = 0, ans = inf;
  for (long long i = 1; i < n + 1; i++) {
    cin >> c[i];
  }
  for (long long i = 0; i < 2; i++) {
    long long cnt;
    cin >> cnt;
    while (cnt--) {
      long long x;
      cin >> x;
      v[x] |= 1 << i;
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    second[v[i]].insert(c[i]);
  }
  for (auto z : second[3]) cur += z;
  it[3] = second[3].end();
  ptr[3] = second[3].size();
  for (long long i = 0; i < 3; i++) {
    it[i] = second[i].begin();
    ptr[i] = 0;
  }
  for (long long both = m; both >= 0; both--) {
    while (ptr[3] > m) {
      ptr[3]--;
      it[3]--;
      cur -= *it[3];
    }
    while (ptr[0] + ptr[1] + ptr[2] < m - both) {
      long long best = inf;
      long long best_j = -1;
      for (long long j = 0; j < 3; j++) {
        num[j] = (it[j] == second[j].end() ? inf : *it[j]);
        if (num[j] < best) {
          best = num[j];
          best_j = j;
        }
      }
      if (best_j == -1) break;
      cur += *it[best_j];
      it[best_j]++;
      ptr[best_j]++;
    }
    for (long long t = 1; t < 3; t++) {
      while (ptr[t] + both < k && it[t] != second[t].end()) {
        if (ptr[0] == 0 && ptr[3 - t] + both <= k) break;
        auto it0 = it[0];
        auto it3t = it[3 - t];
        if (ptr[3 - t] + both <= k or (ptr[0] != 0 && *--it0 > *--it3t)) {
          it[0]--;
          ptr[0]--;
          cur -= *it[0];
        } else {
          it[3 - t]--;
          ptr[3 - t]--;
          cur -= *it[3 - t];
        }
        cur += *it[t];
        it[t]++;
        ptr[t]++;
      }
    }
    if (ptr[3] == both && ptr[1] + both >= k && ptr[2] + both >= k &&
        ptr[0] + ptr[1] + ptr[2] + ptr[3] == m)
      ans = min(ans, cur);
  }
  cout << (ans == inf ? -1 : ans);
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
  ;
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
