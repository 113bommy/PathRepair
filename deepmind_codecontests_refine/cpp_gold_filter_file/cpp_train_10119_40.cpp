#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e6 + 7;
const long long mod = 998244353;
const long long INF = 1e9;
long long powmod(long long a, long long b) {
  a %= mod;
  if (a == 0) return 0;
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = res * a;
      res %= mod;
    }
    a = a * a;
    a %= mod;
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long arr[n][k];
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> ch;
      arr[i][j] = ch - '0';
    }
  }
  int in[k];
  for (int i = 0; i < k; i++) {
    in[i] = i;
  }
  long long ans = INF;
  do {
    long long int mi = INF, ma = -INF, x;
    for (int i = 0; i < n; i++) {
      x = 0;
      for (int j = 0; j < k; j++) {
        x = x * 10 + arr[i][in[j]];
      }
      ma = max(ma, x);
      mi = min(mi, x);
    }
    ans = min(ans, ma - mi);
  } while (next_permutation(in, in + k));
  cout << ans << endl;
  return 0;
}
