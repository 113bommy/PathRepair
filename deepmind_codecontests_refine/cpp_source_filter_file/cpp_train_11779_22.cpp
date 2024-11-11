#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[3];
  long long b[3];
  for (long long &i : a) cin >> i;
  for (long long &i : b) cin >> i;
  long long q = b[0] - a[0];
  if (q >= 0 && q + b[1] - a[1] >= 0 && q + b[1] - a[1] + b[2] > a[2])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
