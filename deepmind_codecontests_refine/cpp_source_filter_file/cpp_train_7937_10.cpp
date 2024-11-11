#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> p(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == i + 1) {
      p[i] = 1;
      cnt++;
    }
  }
  if (a[0] == 1) {
    for (int i = 1; i < n; i++) {
      if (a[i] == 1) {
        a[i] = 0;
      } else
        break;
    }
    a[0] = 0;
  }
  if (a[n - 1] == 1) {
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == 1)
        a[i] = 0;
      else
        break;
    }
    a[n - 1] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cout << 2 << endl;
      return;
    }
  }
  if (cnt == n) {
    cout << 0 << endl;
    return;
  }
  if (cnt == 0) {
    cout << 1 << endl;
    return;
  }
  cout << 1 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int zz = 1; zz <= t; zz++) {
    solve();
  }
}
