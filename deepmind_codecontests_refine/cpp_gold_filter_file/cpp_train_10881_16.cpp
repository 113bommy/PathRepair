#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, out;
  cin >> n;
  out = n / 2 + n / 3 + n / 5 + n / 7;
  out -= n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35;
  out += n / 30 + n / 42 + n / 70 + n / 105;
  out -= n / 210;
  cout << n - out << "\n";
  return 0;
}
