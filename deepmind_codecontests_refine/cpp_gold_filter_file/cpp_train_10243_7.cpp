#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long int powmod(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int x = powmod(a, b / 2);
  long long int y = (x * x) % 1000000007;
  if (b % 2) return (a * y) % 1000000007;
  return y % 1000000007;
}
int main() {
  string a, b;
  cin >> a >> b;
  int l1 = a.length();
  int l2 = b.length();
  int c1[2], c[2];
  memset(c1, 0, sizeof(c1));
  memset(c, 0, sizeof(c));
  int ind = 0, ind1 = 0, max0 = 0, max1 = 0, count = 0, count1 = 0;
  for (__typeof(l1) i = (0) - ((0) > (l1)); i != (l1) - ((0) > (l1));
       i += 1 - 2 * ((0) > (l1))) {
    if (a[i] == '1') {
      if (ind + 1 == i)
        count++;
      else {
        if (count > max1) max1 = count;
        count = 1;
      }
      ind = i;
      c[1]++;
    } else {
      c[0]++;
    }
  }
  if (count > max1) max1 = count;
  ind1 = 0, count1 = 0, max0 = 0;
  for (__typeof(l2) i = (0) - ((0) > (l2)); i != (l2) - ((0) > (l2));
       i += 1 - 2 * ((0) > (l2))) {
    if (b[i] == '1') {
      if (ind1 + 1 == i)
        count1++;
      else {
        if (count1 > max0) max0 = count1;
        count1 = 1;
      }
      ind1 = i;
      c1[1]++;
    } else
      c1[0]++;
  }
  if (count1 > max0) max0 = count1;
  if (c1[1] <= c[1])
    cout << "YES\n";
  else if (c1[1] - c[1] > 1)
    cout << "NO\n";
  else if (c1[1] - c[1] == 1) {
    if (c1[1] % 2 == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  } else
    cout << "YES\n";
  return 0;
}
