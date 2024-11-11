#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long MAX = 1e6 + 5;
long long n, k;
long long koszt[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  cin >> n >> k;
  if (k == 1) {
    cout << 3 << "\n";
    return 0;
  }
  for (long long i = (0); i <= ((long long)(n + 1) - 1); i++) koszt[i] = i;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 2; i * j <= n; j++) {
      koszt[i * j] -= koszt[i];
    }
  }
  sort(koszt, koszt + n + 1);
  long long sum = 0;
  for (long long i = (0); i <= ((long long)(k + 3) - 1); i++) {
    sum += koszt[i];
  }
  cout << sum << "\n";
}
