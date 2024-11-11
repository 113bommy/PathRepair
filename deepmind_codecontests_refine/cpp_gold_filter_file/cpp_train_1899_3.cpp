#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long x, long long y, long long z) {
  long long res = 1, num = x;
  while (y > 0) {
    if (y & 1) res = (res * num) % z;
    num = (num * num) % z;
    y = y >> 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    int d, m;
    cin >> d >> m;
    int k = d;
    bool A[30] = {0};
    for (int i = 0; i <= 29; i++) {
      A[i] = k % 2;
      k /= 2;
    }
    int msb;
    for (int i = 29; i >= 0; i--) {
      if (A[i]) {
        msb = i;
        break;
      }
    }
    int d1 = 0;
    for (int i = 0; i <= msb - 1; i++) {
      if (A[i]) d1 += (1 << i);
    }
    long long ans = 1;
    for (int i = 1; i <= 30; i++) {
      if (i == msb + 1) {
        ans = ans * (d1 + 2) % m;
        break;
      }
      ans = ans * ((1 << (i - 1)) + 1) % m;
    }
    ans--;
    ans = (ans + m) % m;
    cout << ans << endl;
  }
}
