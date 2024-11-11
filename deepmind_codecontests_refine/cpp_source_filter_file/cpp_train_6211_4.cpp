#include <bits/stdc++.h>
using namespace std;
char cn;
int p[181][181], a[250001], b, c[250001], n, i, g;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> cn >> a[i] >> cn >> b >> cn >> cn >> c[i];
    a[i] += b;
    g = gcd(a[i], c[i]);
    a[i] /= g;
    c[i] /= g;
    p[a[i]][c[i]]++;
  }
  for (i = 1; i <= n - 1; i++) cout << p[a[i]][c[i]] << " ";
  cout << p[a[n]][c[n]] << '\n';
  return 0;
}
