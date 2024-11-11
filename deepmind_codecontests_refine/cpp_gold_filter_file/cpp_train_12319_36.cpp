#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
const long long int INF = 1011111111;
const long long int LLINF = 1000111000111000111LL;
const long double EPS = 1e-10;
const long double PI = 3.14159265358979323;
using namespace std;
long long int power(long long int base, long long int exponent) {
  long long int ans = 1;
  while (exponent != 0) {
    if (exponent & 1) ans = (1LL * ans * base);
    base = (1LL * base * base);
    exponent >>= 1;
  }
  return ans;
}
long long int mask[(1ll << 22)];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, k;
  cin >> n;
  for (i = 0; i < (1ll << 22); i++) mask[i] = -1;
  vector<long long int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    mask[v[i]] = i;
  }
  for (i = 0; i < 22; i++) {
    for (j = 0; j < (1ll << 22); j++) {
      if (mask[j] != -1) {
        mask[j | (1ll << i)] = mask[j];
      }
    }
  }
  for (i = 0; i < n; i++) {
    long long int temp = v[i];
    for (j = 0; j < 22; j++) {
      temp ^= (1ll << j);
    }
    if (mask[temp] == -1)
      cout << -1 << " ";
    else
      cout << v[mask[temp]] << " ";
  }
  cerr << '\n'
       << "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
}
