#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch())
        .count());
inline int dice() {
  static std::uniform_int_distribution<int> uid(0, 100);
  return uid(rng);
}
long long check(long long l, long long r) {
  cout << l << " " << r << endl;
  string s;
  cin >> s;
  return s == "Yes";
}
int main() {
  long long n, k, i, j;
  cin >> n >> k;
  long long lo = 1, hi = n, mid;
  while (hi - lo > 1) {
    if (hi - lo <= 50) {
      long long t = dice() % (hi - lo + 1) + lo;
      if (check(t, t)) exit(0);
      lo = max(lo - k, 1LL);
      hi = min(hi + k, n);
      continue;
    }
    mid = (hi + lo) / 2;
    if (check(lo, mid)) {
      hi = min(mid + k, n);
      lo = max(1LL, lo - k);
    } else {
      lo = max(1LL, mid - k);
      hi = min(n, hi + k);
    }
    long long t = dice() % (hi - lo + 1);
  }
  return 0;
}
