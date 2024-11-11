#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    long long b = binpow(a, n / 2);
    return b * b;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  int ans_now(0);
  if (n == 1) {
    cout << "YES\n" << x;
  } else if (n == 2 and x == 0) {
    cout << "NO";
  } else if (n == 2) {
    cout << "YES\n";
    cout << 0 << " " << x;
  } else {
    cout << "YES\n";
    for (int i = 1; i <= n - 3; i++) {
      cout << i << " ";
      ans_now ^= i;
    }
    int pff1(1 << 18), pff2(1 << 17);
    ans_now ^= pff1;
    ans_now ^= pff2;
    int y = ans_now ^ x;
    ans_now ^= y;
    if (y > n - 3 and ans_now == x) {
      cout << pff1 << " " << pff2 << " " << y;
    } else {
      cout << "blet";
    }
  }
  return 0;
}
