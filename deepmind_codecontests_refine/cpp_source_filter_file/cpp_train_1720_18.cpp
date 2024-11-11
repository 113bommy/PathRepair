#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k;
  long long n, m;
  cin >> n;
  m = sqrt(n * 2);
  j = m * (m + 1) / 2;
  if (j > n)
    ;
  {
    m--;
    j = m * (m + 1) / 2;
  }
  k = n % j;
  if (!k)
    cout << m << endl;
  else
    cout << k << endl;
  return 0;
}
