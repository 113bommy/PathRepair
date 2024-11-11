#include <bits/stdc++.h>
using namespace std;
int digits(long long n) {
  int ans = 0;
  while (n) {
    ans++;
    n /= 10;
  }
  return ans;
}
int main() {
  long long w, m, k;
  cin >> w >> m >> k;
  long long n = digits(m), next = round(pow(10, n)), ans = 0;
  while (w > 0) {
    if ((next - m) * k * n >= w) {
      cout << ans + (long long)(w / (k * n));
      return 0;
    } else {
      ans += next - m;
      w -= (next - m) * k * n;
      m = next;
      next *= 10;
      n++;
    }
  }
  cout << ans;
  return 0;
}
