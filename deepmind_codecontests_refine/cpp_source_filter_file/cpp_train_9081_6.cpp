#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long a;
vector<long long> m, n;
long long vozr(vector<long long> &u) {
  for (int q = 1; q < u.size(); q++)
    if (u[q - 1] >= u[q]) return 0;
  return 1;
}
long long ubiv(vector<long long> &u) {
  for (int q = 1; q < u.size(); q++)
    if (u[q - 1] <= u[q]) return 0;
  return 1;
}
void GO_BACK(vector<long long> &u) {
  for (int q = a - 1; q > 0; q--) u[q] -= u[q - 1];
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  cin >> a;
  m = vector<long long>(a);
  n = vector<long long>(a);
  for (int q = 0; q < a; q++) cin >> m[q];
  for (int q = 0; q < a; q++) cin >> n[q];
  if (a == 1) {
    if (m[0] != n[0])
      cout << "IMPOSSIBLE";
    else
      cout << "SMALL\n0";
    exit(0);
  }
  if (m == n) cout << "SMALL\n0", exit(0);
  reverse(m.begin(), m.end());
  if (m == n) cout << "SMALL\n1\nR", exit(0);
  reverse(m.begin(), m.end());
  if (a >= 3) {
    string o;
    int fl = 1;
    for (;;) {
      if (n == m) break;
      reverse(m.begin(), m.end());
      if (n == m) {
        o.push_back('R');
        break;
      }
      reverse(m.begin(), m.end());
      if (ubiv(n)) {
        o.push_back('R');
        reverse(n.begin(), n.end());
      }
      if (vozr(n)) {
        o.push_back('P');
        GO_BACK(n);
      } else {
        if (n == m) break;
        o.push_back('R');
        reverse(n.begin(), n.end());
        fl = n == m;
        break;
      }
    }
    if (!fl) cout << "IMPOSSIBLE", exit(0);
    int opP = 0;
    for (char c : o) opP += c == 'P';
    if (opP > 200000)
      cout << "BIG\n" << opP;
    else {
      assert(o.size() <= 500000);
      cout << "SMALL\n";
      cout << o.size() << "\n";
      reverse(o.begin(), o.end());
      cout << o;
    }
    exit(0);
  }
  long long x = n[0], y = n[1];
  vector<pair<char, long long>> O;
  int fl = 1;
  long long MS = m[0] + m[1], SM = 0;
  for (;;) {
    if (m[0] == x && m[1] == y) break;
    if (m[0] == y && m[1] == x) {
      O.push_back({'R', 1});
      break;
    }
    if (fl == -1) {
      fl = 1;
      break;
    }
    if (x > y) {
      swap(x, y);
      if (SM <= 2000000) O.push_back({'R', 1});
    }
    if (x < y) {
      long long stS = x + y;
      long long skok = (y - 1) / x;
      long long fnS = stS - skok * x;
      if (fnS <= MS && MS <= stS) {
        long long delta = stS - MS;
        if (delta % x) {
          fl = 0;
          break;
        }
        skok = delta / x;
        fl = -1;
      }
      if (SM <= 2000000) O.push_back({'P', skok});
      SM += skok;
      y -= skok * x;
    } else {
      fl = m[0] == x && m[1] == y;
      break;
    }
  }
  if (!fl) cout << "IMPOSSIBLE", exit(0);
  long long all = 0;
  for (auto p : O) {
    all += p.second;
  }
  if (SM > 200000)
    cout << "BIG\n" << SM;
  else {
    assert(all <= 500000);
    cout << "SMALL\n";
    cout << all << "\n";
    reverse(O.begin(), O.end());
    for (auto p : O) {
      for (int q = 0; q < p.second; q++) cout << p.first;
    }
  }
}
