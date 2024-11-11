#include <bits/stdc++.h>
using namespace std;
long long L, R, K;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> R >> K;
  long long i;
  if (R - L + 1 <= 10) {
    vector<int> V;
    long long ans = 1e15;
    for (i = 1; i < (1 << (R - L + 1)); ++i) {
      if (__builtin_popcount(i) > K) continue;
      long long j = i;
      long long logarthm = 0;
      long long val = 0;
      while (j) {
        if (j & 1) val ^= L + logarthm;
        j /= 2;
        ++logarthm;
      }
      if (val < ans) {
        V.clear();
        logarthm = 0;
        j = i;
        ans = val;
        while (j) {
          if (j & 1) V.push_back(L + logarthm);
          j /= 2;
          ++logarthm;
        }
      }
    }
    cout << ans << "\n";
    cout << V.size() << "\n";
    for (auto v : V) cout << v << " ";
    return 0;
  }
  if (K >= 4) {
    if (L % 2) ++L;
    cout << 0 << '\n'
         << 4 << '\n'
         << L << " " << L + 1 << " " << L + 2 << " " << L + 3;
    return 0;
  }
  if (K >= 3) {
    long long J = 1, M = 2, H = 3;
    while (H <= R) {
      if (J >= L) {
        cout << 0 << '\n' << 3 << '\n' << J << " " << M << " " << H;
        return 0;
      }
      H *= 2;
      J *= 2;
      ++J;
      M *= 2;
      ++M;
    }
  }
  if (K >= 2) {
    if (L % 2) ++L;
    cout << 1 << '\n' << 2 << '\n' << L << " " << L + 1 << '\n';
    return 0;
  }
  cout << L << '\n' << 1 << '\n' << L;
  return 0;
}
