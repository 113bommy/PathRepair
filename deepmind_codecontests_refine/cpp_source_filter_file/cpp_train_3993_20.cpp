#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, m, n;
  cin >> n >> m >> a;
  if (n % a != 0 && m % a != 0)
    cout << ((n / a) + 1) * ((m / a) + 1);
  else if (n % a == 0 && m % a == 0)
    cout << (n / a) * (m / a);
  else if (n % a != 0 && m % a == 0)
    cout << ((n / a) + 1) * ((m / a));
  else if (n % a == 0 && m % a != 0)
    cout << ((n / a)) * ((m / a) + 1);
  return 0;
}
