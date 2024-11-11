#include <bits/stdc++.h>
using namespace std;
vector<int> divisors(13);
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long a, b;
  cin >> a >> b;
  long long g = 1;
  long long m = min(a, b);
  for (int i = 1; i <= m; i++) g *= i;
  cout << g;
  return 0;
}
