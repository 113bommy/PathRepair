#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int a, b, c, n, max, sum;
  cin >> t;
  while (t) {
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> n;
    max = c > (a > b ? a : b) ? c : (a > b ? a : b);
    sum = a + b + c + n;
    if (sum % 3 == 0 && (sum / 3) >= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    t--;
  }
  return 0;
}
