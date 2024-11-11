#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1000000007;
double eps = 1e-12;
long long modu(long long a, long long b, long long c) {
  if (b == 0) return 1;
  if (b % 2) {
    return (a % c * modu(a, b - 1, c)) % c;
  } else {
    long long y = modu(a, b / 2, c);
    return (y * y) % c;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long ceil2(long long a, long long b) {
  long long res = a / b;
  if (b * res != a) res += (a > 0) & (b > 0);
  return res;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) {
    return a * power(a * a, b / 2);
  } else
    return power(a * a, b / 2);
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
      cout << "Infinite\n";
      return;
    }
  }
  long long cnt = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] == 1) {
      cnt += (a[i - 1] == 2) ? 3 : 4;
    } else if (a[i] == 2) {
      cnt += 3;
    } else {
      cnt += 4;
    }
  }
  for (long long i = 0; i < n - 2; i++) {
    if (a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) cnt--;
  }
  cout << "Finite\n";
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
