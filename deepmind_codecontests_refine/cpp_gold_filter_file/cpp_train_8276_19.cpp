#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, sum = 0, count = 0, m, z, min, hr;
  string a;
  cin >> a;
  n = (a[0] - '0') * 10 + (a[1] - '0');
  m = (a[3] - '0') * 10 + (a[4] - '0');
  cin >> z;
  min = z % 60;
  hr = z / 60;
  n = n + hr;
  m = min + m;
  while (m > 59) {
    n = n + 1;
    m = m - 60;
  }
  while (n > 23) {
    n = n - 24;
  }
  if (n < 10 && m < 10)
    cout << "0" << n << ":"
         << "0" << m;
  else if (n < 10)
    cout << "0" << n << ":" << m;
  else if (m < 10)
    cout << n << ":"
         << "0" << m;
  else
    cout << n << ":" << m;
  return 0;
}
