#include <bits/stdc++.h>
using namespace std;
long long chk(long long n) {
  if (n < 2) return 0;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long rev(long long n) {
  long long ans = 0;
  while (n) {
    ans *= 10;
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  long long d;
  cin >> d;
  for (long long i = 1;; ++i) {
    if ((i != rev(i)) && (chk(i) && chk(rev(i)))) {
      d--;
      if (d == 0) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
