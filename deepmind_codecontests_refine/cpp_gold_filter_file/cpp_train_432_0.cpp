#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = *(max_element(a, a + n));
  for (int i = 0; i < n; i++) {
    a[i] = x - a[i];
  }
  int z = a[0];
  for (int i = 1; i < n; i++) {
    z = gcd(z, a[i]);
  }
  long long y = 0;
  for (int i = 0; i < n; i++) {
    y += a[i] / z;
  }
  cout << y << " " << z;
}
