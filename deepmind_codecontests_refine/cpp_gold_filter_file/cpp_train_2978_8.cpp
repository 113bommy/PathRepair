#include <bits/stdc++.h>
using namespace std;
unsigned long long dsum(unsigned long long n) {
  unsigned long long res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
int main() {
  unsigned long long n, s;
  cin >> n >> s;
  unsigned long long dif = n - dsum(n);
  if (dif < s)
    cout << 0 << endl;
  else {
    unsigned long long l = 1, h = n;
    while (h - l > 0) {
      unsigned long long mid = l + (h - l) / 2;
      unsigned long long x = dsum(mid);
      dif = mid - x;
      if (dif < s) {
        l = mid + 1;
      } else
        h = mid;
    }
    if (n - dsum(l) >= s) l--;
    cout << n - l << endl;
  }
}
