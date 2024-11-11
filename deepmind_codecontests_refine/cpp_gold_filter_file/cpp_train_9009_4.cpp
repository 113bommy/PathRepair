#include <bits/stdc++.h>
using namespace std;
const int MAXN = int(1e5) + 10;
const int MOD = int(1e4) + 7;
int n;
long long a[MAXN], b[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = b[i] = x;
  }
  sort(a, a + n);
  sort(b, b + n);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res = (res + a[i] * b[n - i - 1] % MOD) % MOD;
  }
  cout << res;
}
