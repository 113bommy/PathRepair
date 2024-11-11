#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
const long long MAXN = 1e5 + 7;
template <long long SZ>
struct Sieve {
  bitset<SZ> pri;
  vector<long long> pr;
  Sieve() {
    pri.set();
    pri[0] = pri[1] = 0;
    for (int i = 4; i < SZ; i += 2) {
      pri[i] = 0;
    }
    for (int i = 3; i * i < SZ; i += 2) {
      if (pri[i]) {
        for (int j = i * i; j < SZ; j += 2 * i) {
          pri[j] = 0;
        }
      }
    }
    for (int i = 2; i < SZ; i++) {
      if (pri[i]) {
        pr.push_back(i);
      }
    }
  }
};
void check() {
  Sieve<MAXN> Si;
  string s;
  cin >> s;
  long long cnt[100] = {0}, m = 0, n = s.size();
  for (char i : s) {
    cnt[i - 'a']++;
  }
  for (long long i = 0; i < 30; i++)
    if (cnt[i] > cnt[m]) m = i;
  char t[1001];
  t[n] = 0;
  long long q = 0;
  for (long long i = 1; i <= n; i++) {
    if (i == 1 || (i > n / 2 && Si.pri[i])) {
      while (q < 26 && (cnt[q] == 0 || q == m)) q++;
      if (q == 26) {
        cnt[m]--;
        t[i - 1] = m + 'a';
      } else {
        cnt[q]--;
        t[i - 1] = q + 'a';
      }
    } else {
      if (cnt[m] == 0) {
        cout << "NO\n";
        return;
      } else {
        cnt[m]--;
        t[i - 1] = m + 'a';
      }
    }
  }
  cout << "YES\n" << t;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    check();
  }
  return 0;
}
