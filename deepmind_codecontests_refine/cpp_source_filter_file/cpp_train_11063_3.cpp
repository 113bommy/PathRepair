#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int cdiv(long long int a, long long int b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
long long int myMod(long long int a, long long int b) {
  long long int r = a % b;
  return r < 0 ? r + b : r;
}
long long int ModPow(long long int a, long long int b, long long int M) {
  if (M == 1) return 0;
  a %= M;
  long long int ans = 1, t = 1;
  while (t > 0 && t <= b) {
    if (t & b) {
      ans *= a;
      ans %= M;
    }
    t <<= 1;
    a *= a;
    a %= M;
  }
  return ans;
}
long long int Pow(long long int a, long long int b) {
  if (M == 1) return 0;
  long long int ans = 1, t = 1;
  while (t > 0 && t <= b) {
    if (t & b) {
      ans *= a;
    }
    t <<= 1;
    a *= a;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int ts;
  cin >> ts;
  while (ts--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    ;
    long long int co = 0, cz = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == 1)
        co++;
      else
        cz++;
    }
    if (co == cz) {
      cout << n / 2 << "\n";
      for (long long int i = 0; i < n / 2; i++) cout << "0 ";
      cout << "\n";
      ;
    } else if (co < cz) {
      cout << cz << "\n";
      for (long long int i = 0; i < cz; i++) cout << "0 ";
      cout << "\n";
      ;
    } else {
      if (n % 2 != 0) {
        cout << co - 1 << "\n";
        for (long long int i = 0; i < co - 1; i++) cout << "1 ";
        cout << "\n";
        ;
      } else {
        cout << co << "\n";
        for (long long int i = 0; i < co; i++) cout << "1 ";
        cout << "\n";
        ;
      }
    }
  }
  return 0;
}
