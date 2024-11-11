#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int abs1(long long int a) {
  if (a < 0)
    return -1 * a;
  else
    return a;
}
long long int power(long long int base, long long int n, long long int M) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long int halfn = power(base, n / 2, M);
  if (n % 2 == 0)
    return (halfn * halfn) % M;
  else
    return (((halfn * halfn) % M) * base) % M;
}
long long int findMMI(long long int n, long long int M) {
  return power(n, M - 2, M);
}
long long int max2(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max2(max2(a, b), c);
}
long long int min2(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long int min3(long long int a, long long int b, long long int c) {
  return min2(min2(a, b), c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, tn;
  cin >> n;
  tn = n;
  set<int> v;
  map<int, int> ma;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t > n) {
      tot++;
      tn--;
    } else
      v.insert(t);
  }
  cout << tot + (tn - v.size());
  return 0;
}
