#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
int main() {
  long long n, m1 = 0, m2 = 0;
  cin >> n;
  vector<long long> arr1(n), arr2(n);
  for (int i = 0; i < int(n); ++i) cin >> arr1[i];
  for (int i = 0; i < int(n); ++i) cin >> arr2[i];
  m1 = arr1[0];
  for (int i = int(1); i < int(n); ++i) m1 |= arr1[i];
  m2 = arr2[0];
  for (int i = int(1); i < int(n); ++i) m2 |= arr2[i];
  cout << m1 + m2 << endl;
  return 0;
}
