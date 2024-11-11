#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int maxn = 1e5 + 100;
int n, x;
int a[maxn];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    a[x]++;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i < n + 1; i++) {
    if (a[i] == 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
