#include <bits/stdc++.h>
using namespace std;
const int INF = 2137383647;
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
int main() {
  long long c, h1, h2, w1, w2;
  cin >> c >> h1 >> h2 >> w1 >> w2;
  long long q = LCM(w1, w2);
  long long val1 = (q / w1) * h1;
  long long val2 = (q / w2) * h2;
  long long ans = 0;
  if (c / q > 0) {
    ans = val1 > val2 ? (c / q - 1) * val1 : (c / q - 1) * val2;
    c %= q;
    c += q;
  }
  if (w1 < w2) {
    swap(w1, w2);
    swap(h1, h2);
  }
  long long maxans = 0;
  long long cur = 0;
  while (w1 * cur <= c) {
    long long curans = cur * h1 + (c - (w1 * cur)) / w2 * h2;
    maxans = max(maxans, curans);
    ++cur;
  }
  cout << ans + maxans << endl;
  return 0;
}
