#include <bits/stdc++.h>
using namespace std;
const double TL = 1.5 * CLOCKS_PER_SEC;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> get_row(long long r) {
  long long p = 1, s = 0, l = 0;
  for (;; p *= 4) {
    if (s + p >= r) {
      break;
    }
    l += 2;
    s += p;
  }
  long long d = r - s - 1;
  long long a = d + p;
  long long b = 2LL << l;
  for (int i = 0; i < l; i += 2) {
    long long x = (d % (1LL << (i + 2))) / (1LL << i);
    long long y = (d % (1LL << (i + 2))) / (1LL << i);
    if (x == 2 || x == 3) {
      b |= (1LL << i);
    }
    if (y == 1 || y == 2) {
      b |= (1LL << (i + 1));
    }
  }
  long long c = a ^ b;
  return {a, b, c};
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    cin >> n;
    n -= 1;
    long long x = n / 3 + 1, y = n % 3;
    vector<long long> ans = get_row(x);
    cout << ans[y] << endl;
  }
  return 0;
}
