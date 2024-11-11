#include <bits/stdc++.h>
using namespace std;
long long a, b, n, k, lm, kp, i;
int main() {
  cin >> a >> b >> n;
  k = a % b;
  for (i = 0; i <= 9; i++)
    if ((k + i) % b == 0) break;
  if (i == 10) {
    cout << -1 << endl;
    return 0;
  }
  cout << a << i;
  for (i = 1; i < n; i++) cout << "0";
  cout << endl;
}
