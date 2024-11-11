#include <bits/stdc++.h>
using namespace std;
int n;
bool isp(int x) {
  bool koft = 0;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) koft = 1;
  if (koft) return 0;
  return 1;
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b % 2 == 0)
    return power(a, b / 2) * power(a, b / 2) % n;
  else
    return power(a, b / 2) * power(a, b / 2) % n * a % n;
}
int main() {
  cin >> n;
  if (n == 1) return cout << "YES\n1\n", 0;
  if (n == 4) return cout << "YES\n1\n3\n4\n2\n", 0;
  if (!isp(n)) return cout << "NO\n", 0;
  cout << "YES\n1\n";
  for (long long i = 2; i < n; i++) cout << i * power(i - 1, n - 2) % n << '\n';
  cout << n << '\n';
}
