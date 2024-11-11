#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << -1;
  else if (n % 2)
    cout << "-" << 1 + (n / 2);
  else if (n % 2 == 0)
    cout << n / 2;
  return 0;
}
