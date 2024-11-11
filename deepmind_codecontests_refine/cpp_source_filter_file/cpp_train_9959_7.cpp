#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int t = power(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
long long int modInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, j, k, l, w;
  cin >> n >> w;
  long long int ar[n], sm[n + 1];
  sm[0] = 0;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (i = 0; i < n; i++) {
    sm[i + 1] = sm[i] + ar[i];
  }
  long long int mx = 0, mn = 0;
  for (i = 1; i <= n; i++) {
    if (sm[i] < mn) mn = sm[i];
    if (sm[i] > mx) mx = sm[i];
  }
  long long int a, b;
  a = (w - mx);
  b = abs(mn);
  if ((a - b + 1) > 0) {
    cout << (a - b + 1) << endl;
  } else
    cout << "-1";
  return 0;
}
