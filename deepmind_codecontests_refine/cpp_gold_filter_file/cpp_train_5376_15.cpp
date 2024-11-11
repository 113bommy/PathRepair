#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long p = pow(2, n);
  if (m < p)
    cout << m << endl;
  else
    cout << m % p << endl;
  return 0;
}
