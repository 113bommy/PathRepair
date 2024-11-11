#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c;
    if (a >= c)
      cout << "-1 ";
    else
      cout << "1 ";
    d = 1000000000 - (1000000000) % b;
    if ((d / b) * c >= a * d)
      cout << "-1\n";
    else
      cout << d << endl;
  }
  return 0;
}
