#include <bits/stdc++.h>
using namespace std;
int k;
unsigned long long f[65][65], m;
unsigned long long find(int n, int m) {
  if (m < 0) return 0;
  if (n < m) return 0;
  return f[n][m];
}
unsigned long long find1(unsigned long long x) {
  unsigned long long ans = 0;
  int K = 0;
  for (int i = 63; i >= 0; --i) {
    if ((x >> i) & 1) ans = ans + find(i, k - K), ++K;
  }
  return ans;
}
unsigned long long check(unsigned long long x) {
  return find1(2 * x) - find1(x);
}
int main() {
  for (int i = 0; i < 65; ++i)
    for (int j = 0; j <= i; ++j)
      f[i][j] = (j == 0) ? 1 : (f[i - 1][j] + f[i - 1][j - 1]);
  cin >> m >> k;
  unsigned long long head = 0, tail = (unsigned long long)1 << 63;
  while (head < tail - 1) {
    unsigned long long mid = (head + tail) >> 1;
    if (check(mid) >= m)
      tail = mid;
    else
      head = mid;
  }
  cout << tail << endl;
}
