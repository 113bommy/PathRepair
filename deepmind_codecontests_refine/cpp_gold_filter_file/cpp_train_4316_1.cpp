#include <bits/stdc++.h>
using namespace std;
long long d1, d2, tests, n, k, d, ans;
long long tob;
long long v1, v2, v3, has, need;
long long up, dwn;
void check() {
  long long temp = k - has;
  if (temp < 0 || temp % 3 > 0) return;
  long long rem = n - k;
  rem -= need;
  if (rem < 0) return;
  if (rem % 3) return;
  ans = 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> tests;
  for (; tests; --tests) {
    cin >> n >> k >> d1 >> d2;
    ans = 0;
    for (int mask = 0; mask < 4; mask++) {
      v1 = 0;
      v2 = v1;
      if (mask & 1)
        v2 -= d1;
      else
        v2 += d1;
      v3 = v2;
      if (mask & 2)
        v3 -= d2;
      else
        v3 += d2;
      up = max(max(v1, v2), v3);
      dwn = min(min(v1, v2), v3);
      has = v1 + v2 + v3 - dwn * 3;
      need = up * 3 - v1 - v2 - v3;
      check();
    }
    if (ans)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  cin.get();
  cin.get();
  return 0;
}
