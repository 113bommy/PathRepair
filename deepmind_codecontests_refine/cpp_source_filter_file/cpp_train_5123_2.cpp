#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const int mod = (int)998244353;
const int MAXN = (int)3e5 + 5;
long long n;
int E[MAXN];
long long bp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b / 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  E[0] = 0;
  long long in10 = bp(100, mod - 2);
  for (int i = 1; i <= n; i++) {
    int cur;
    cin >> cur;
    long long inv = 100 * bp(cur, mod - 2) % mod;
    E[i] = E[i - 1] + (inv - 1 + mod) % mod * E[i - 1] + inv;
    E[i] %= mod;
  }
  cout << E[n] << '\n';
}
