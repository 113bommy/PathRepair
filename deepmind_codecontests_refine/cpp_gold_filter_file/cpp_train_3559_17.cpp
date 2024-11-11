#include <bits/stdc++.h>
using namespace std;
long long digit(long long x) {
  long long cnt = 0;
  while (x > 0) {
    cnt += x & 1;
    x >>= 1;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int Case = 1;
  while (Case--) {
    long long n, p;
    cin >> n >> p;
    long long ans = -1;
    for (int i = 1; i < 40; i++) {
      long long x = n - (p * i);
      if (digit(x) <= i and digit(x) and x >= i) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
