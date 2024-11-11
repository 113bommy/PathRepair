#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long quickpow(long long a, long long b) {
  long long ans = 1;
  a = a % mod;
  while (b > 0) {
    if (b % 2) ans = ans * a;
    b = b / 2;
    a = a * a;
  }
  return ans;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int a[500005];
int tmp[500005];
int main() {
  ios::sync_with_stdio(false);
  int n, r1, r2;
  cin >> n >> r1 >> r2;
  for (int i = 1; i <= n; i++) {
    if (i == r1) {
      a[i] = r1;
      tmp[i] = r1;
    } else {
      int x;
      cin >> x;
      a[i] = x;
      tmp[i] = x;
    }
  }
  int nw = r2;
  while (1) {
    if (a[nw] == r1) {
      a[r1] = nw;
      break;
    } else {
      a[tmp[nw]] = nw;
      nw = tmp[nw];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != r2) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
}
