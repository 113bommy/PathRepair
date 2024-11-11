#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long a[4];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if ((a[1] - a[0]) % 2 == 0)
    cout << a[1] << endl;
  else
    cout << a[2] << endl;
  return 0;
}
