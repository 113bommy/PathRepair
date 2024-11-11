#include <bits/stdc++.h>
using namespace std;
int cntbits(long long x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x = x & (x - 1);
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l;
    cin >> l;
    long long ans = cntbits(l);
    ans = 1LL << ans;
    cout << ans;
  }
  return 0;
}
