#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long mod) {
  long long sum = 1;
  while (b) {
    if (b & 1) {
      sum = (sum * a) % mod;
      b--;
    }
    b /= 2;
    a = a * a % mod;
  }
  return sum;
}
const double Pi = acos(-1.0);
const double epsilon = Pi / 180.0;
const int maxn = 2e5 + 10;
long long b[4100];
long long f[4100];
long long a[4100];
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      cin >> b[i];
    }
    long long maxx = b[1];
    long long cnt = 1;
    long long tail = 0;
    for (int i = 2; i <= 2 * n; i++) {
      if (b[i] > maxx) {
        maxx = b[i];
        a[++tail] = cnt;
        cnt = 1;
      } else {
        cnt++;
      }
    }
    a[++tail] = cnt;
    sort(a + 1, a + 1 + tail);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (long long i = 1; i <= tail; ++i) {
      for (long long j = n; j >= a[i]; j--) {
        f[j] = f[j - a[i]];
      }
    }
    if (f[n] == 0)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
