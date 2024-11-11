#include <bits/stdc++.h>
using namespace std;
const int L = 5e6 + 10;
long long sq[L];
int buf[2 * L + 10];
int main() {
  auto cnt = buf + 2 * L;
  long long n, m;
  cin >> n >> m;
  long long ret = 0;
  for (int b = 1; b <= n; b++) {
    long long s = b * b;
    sq[b] = s;
    if (s - m <= 0) {
      cnt[-2 * b + 1]++;
      cnt[0]--;
      ret += 2 * (s - b);
    } else {
      int p = lower_bound(sq, sq + b, s - m) - sq;
      cnt[-2 * b + 1]++;
      cnt[-b - p + 1]--;
      cnt[-b + p]++;
      cnt[0]--;
      ret += 2 * (m - (b - p));
    }
  }
  for (int i = -2 * n; i <= 0; i++) {
    cnt[i] += cnt[i - 1];
    if (cnt[i] > 0) {
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
