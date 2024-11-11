#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
void read(){};
template <typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}
void print(){};
template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}
void solve() {
  int n;
  read(n);
  string s, t;
  cin >> s >> t;
  int p = count(s.begin(), s.end(), '1');
  int q = count(t.begin(), t.end(), '1');
  if (p != q) {
    print(-1);
    return;
  }
  set<int> idx[2];
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      idx[s[i] - '0'].insert(i);
    }
  }
  idx[0].insert(n), idx[1].insert(n);
  int moves = 0;
  while (*idx[0].begin() != n and *idx[1].begin() != n) {
    int cur = 0;
    if (*idx[0].begin() > *idx[1].begin()) cur = 1;
    int val = 0;
    while (true) {
      auto it = idx[cur].lower_bound(val);
      val = *it;
      if (val == n) break;
      idx[cur].erase(it);
      cur ^= 1;
    }
    moves++;
  }
  print(moves);
}
int main() {
  int t;
  t = 1;
  while (t--) solve();
}
