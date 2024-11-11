#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 1e5 + 10;
const int M = 2e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
int m;
int p[N], c[N];
void divide(int n) {
  m = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      p[++m] = i, c[m] = 0;
      while (n % i == 0) {
        n /= i, c[m]++;
      }
    }
  }
  if (n > 1) {
    p[++m] = n;
    c[m] = 1;
  }
}
long long quickpower(int a, long long b) {
  long long ans = 1 % mod;
  for (; b; b >>= 1) {
    if (b & 1) {
      ans = ans * a % mod;
    }
    a = (long long)a * a % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int x;
  long long n;
  cin >> x >> n;
  divide(x);
  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    long long temp = n;
    int a = p[i];
    long long cnt = 0;
    while (temp) {
      cnt += temp / p[i];
      temp /= p[i];
    }
    ans = ans % mod * quickpower(p[i], cnt);
  }
  cout << ans << endl;
  return 0;
}
