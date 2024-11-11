#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long p = pow(2, m);
  if (n < p)
    cout << n << endl;
  else
    cout << n % p << endl;
  return 0;
}
