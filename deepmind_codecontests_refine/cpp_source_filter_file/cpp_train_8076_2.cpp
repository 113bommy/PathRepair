#include <bits/stdc++.h>
using namespace std;
void require(bool cond, const string& message = "Runtime error") {
  if (!cond) {
    cerr << message << endl;
    assert(false);
  }
}
void readData() {}
long long sqr(long long x) { return x * x; }
long long k;
bool inside(long long n, long long i) {
  bool ok = true;
  for (int j = 0; j < int(2); ++j) {
    for (int t = 0; t < int(2); ++t) {
      int i1 = 2 * j - 1;
      int i2 = 2 * t - 1;
      if (sqr(3 * i + i1) + 3 * sqr((n + 1) * 2 - i + i2) > 4 * k * k) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
  }
  for (int j = 0; j < int(2); ++j) {
    int i1 = 2 * j - 1;
    i1 *= 2;
    if (sqr(3 * i + i1) + 3 * sqr(2 * (n + 1) - i) > 4 * k * k) {
      ok = false;
      break;
    }
  }
  return ok;
}
long long shift(long long n) {
  long long l = 0, r = (n + 1) / 2;
  while (l < r) {
    long long m = (l + r) / 2;
    if (inside(n, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  if (!inside(n, l)) {
    l = -1;
  }
  return l;
}
void solve() {
  cin >> k;
  long long n = 0;
  long long ans = 1;
  while (true) {
    if (inside(n, 0)) {
      ans += 6 * (n + 1);
    } else {
      long long s = shift(n);
      if (s == -1) break;
      if (s > 0) {
        ans += 6 * (n + 2 - s);
      } else {
        ans += 6 * (n + 1);
      }
    }
    ++n;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  readData();
  solve();
  return 0;
}
