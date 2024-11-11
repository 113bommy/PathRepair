#include <bits/stdc++.h>
using namespace std;
set<int> prims;
vector<bool> used;
vector<int> divisors;
vector<bool> skip;
vector<int> nxt;
vector<int> prv;
void init_prims(int ub) {
  divisors.resize(ub, 0);
  for (int i = 0; i < ub; ++i) {
    divisors[i] = i;
  }
  for (int i = 2; i < ub; ++i) {
    if (divisors[i] == i) prims.insert(i);
    for (int p : prims) {
      if (i * p >= ub) break;
      divisors[i * p] = p;
      if (i % p == 0) break;
    }
  }
}
vector<int> factors(int x) {
  vector<int> f;
  while (x > 1) {
    int d = divisors[x];
    f.push_back(d);
    while (x % d == 0) x /= d;
  }
  return f;
}
bool is_ok(int x) {
  for (auto f : factors(x)) {
    if (used[f]) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  const int ub = 1300000;
  init_prims(ub);
  used.resize(ub, 0);
  nxt.resize(ub, 0);
  prv.resize(ub, 0);
  skip.resize(ub, false);
  vector<int> v(n, 0);
  for (int i = 0; i < ub - 1; ++i) nxt[i] = i + 1;
  for (int i = 0; i < ub - 1; ++i) prv[i + 1] = i;
  for (int i = 0; i < n; ++i) cin >> v[i];
  bool le = true;
  int lo = 2;
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    int a = v[i];
    int start = le ? a : lo;
    while (skip[start]) start = nxt[start];
    if (!le) lo = nxt[start];
    if (le && start > a) le = false;
    b.push_back(start);
    for (int d : factors(b.back())) {
      for (int j = d; j < ub; j += d) {
        nxt[prv[j]] = nxt[j];
        prv[nxt[j]] = prv[j];
        skip[j] = true;
      }
    }
  }
  for (int x : b) cout << x << " ";
  cout << endl;
  return 0;
}
