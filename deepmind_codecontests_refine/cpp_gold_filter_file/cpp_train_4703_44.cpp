#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 1e6 + 5;
const int inf = 1 << 30;
const long long llf = 9e18;
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
struct node {
  int x, y;
};
bool cmp(int x, int y) { return x < y; }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << 2 * m << endl;
  }
}
