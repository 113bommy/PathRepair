#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(6) << fixed;
  cerr << setprecision(6) << fixed;
  int tests = 1;
  for (int test = 1; test <= tests; ++test) {
    solve();
  }
}
void solve() {
  ll x;
  cin >> x;
  vector<array<ll, 3>> ops;
  auto norm = [&](ll x, ll y, bool flag = false) {
    if (flag) {
      for (int i = 0; i < 30; ++i) {
        ops.push_back({x << i, x << i, 1});
      }
    }
    for (int i = 30; i >= 0; --i) {
      if ((y ^ (x << i)) < y) {
        if (flag) {
          ops.push_back({y, x << i, 1});
        }
        y ^= (x << i);
      }
    }
    return y;
  };
  while (x > 1) {
    ll z = x;
    for (int i = 0; i < 30; ++i) {
      ops.push_back({z, z, 0});
      z *= 2;
      ll y = norm(x, (x ^ z) + x);
      if (y < x && y != 0) {
        ops.push_back({x, z, 1});
        ops.push_back({x ^ z, x, 0});
        norm(x, (x ^ z) + x, true);
        if (!(y & 1)) {
          y = norm(y, x, true);
        }
        x = y;
        break;
      }
    }
  }
  assert((int)(ops).size() < 1e5);
  cout << (int)(ops).size() << endl;
  for (auto op : ops) {
    cout << op[0] << " " << (op[2] ? "^" : "+") << " " << op[1] << "\n";
  }
}
