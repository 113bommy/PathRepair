#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n, m, a;
  cin >> n;
  cin >> m;
  cin >> a;
  long long int c;
  c = (long long)ceil(n / a) * (long long)ceil(m / a);
  cout << c;
  return 0;
}
