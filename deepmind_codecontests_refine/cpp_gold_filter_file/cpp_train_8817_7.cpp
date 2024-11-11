#include <bits/stdc++.h>
using namespace std;
long long bigMOD(long long b) {
  long long r = 1LL;
  long long M = 1000000007LL;
  long long a = 2LL;
  while (b) {
    if (b & 1) r = (r * a + 1000000007) % M;
    b >>= 1, a = (a * a + 1000000007) % M;
  }
  return r % M;
}
int main() {
  long long n, k;
  cin >> n >> k;
  if (!n) {
    puts("0");
    return 0;
  }
  n %= 1000000007;
  long long r = bigMOD(k);
  r = (r * (n + n - 1)) % 1000000007;
  r++;
  while (r < 0) r += 1000000007;
  while (r >= 1000000007) r %= 1000000007;
  cout << r << endl;
  return 0;
}
