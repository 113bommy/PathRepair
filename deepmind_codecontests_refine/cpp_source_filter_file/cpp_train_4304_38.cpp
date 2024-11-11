#include <bits/stdc++.h>
using namespace std;
long long star[18528];
int main() {
  long long i;
  long long k = 1, z = 4;
  long long a;
  star[1] = 1;
  for (i = 2; i <= 18527; i++) {
    star[i] = (z * (z + 1)) / 2 + 3 * k;
    k = k + 2;
    z = z + 3;
  }
  cin >> a;
  cout << star[a] << endl;
  return 0;
}
