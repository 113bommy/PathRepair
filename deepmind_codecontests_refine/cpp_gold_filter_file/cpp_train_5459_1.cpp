#include <bits/stdc++.h>
const int INF = 2009000999;
const double cp = 3.14159265;
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 * n / 2 << endl;
  else
    cout << n / 2 * (n / 2 + 1) << endl;
  for (int(i) = 1; (i) <= (n / 2); i++)
    for (int(j) = (n / 2 + 1); (j) <= (n); j++) cout << i << ' ' << j << endl;
  return 0;
}
