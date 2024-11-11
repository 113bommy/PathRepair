#include <bits/stdc++.h>
using namespace std;
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int cel(int a, int b) { return ((a - 1) / b + 1); }
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, c, f = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (v[0] == v[2 * n - 1])
    cout << -1;
  else
    for (int i = 0; i < 2 * n - 1; i++) cout << v[i] << " ";
  return 0;
}
