#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  constexpr long long p = 1e18;
  const long long l = a - (p % a * 9 % a * 9 % a);
  cout << l << ' ' << l + p - 1 << endl;
}
