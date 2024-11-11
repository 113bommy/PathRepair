#include <bits/stdc++.h>
using namespace std;
long long take(long long n) { return pow(2, int(log2(n)) + 1) - 1; }
long long gen(long long n, long long l, long long r) {
  if (n <= 1) {
    return n;
  } else if (l <= 1 && r >= take(n)) {
    return n;
  }
  return (l <= take(n) / 2 ? gen(n / 2, l, r) : 0) +
         (l <= take(n) / 2 + 1 && r >= take(n) / 2 + 1 ? n % 2 : 0) +
         (r > take(n) / 2 + 1
              ? gen(n / 2, l - take(n) / 2 - 1, r - take(n) / 2 - 1)
              : 0);
}
int main() {
  long long n;
  cin >> n;
  long long l, r;
  cin >> l >> r;
  cout << gen(n, l, r);
  return 0;
}
