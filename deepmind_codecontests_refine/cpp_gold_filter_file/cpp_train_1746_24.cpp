#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  if (n == 1) cout << 4 << endl;
  if (n == 2) cout << 10 << endl;
  if (n == 3) cout << 20 << endl;
  if (n == 4) cout << 35 << endl;
  if (n == 5) cout << 56 << endl;
  if (n == 6) cout << 83 << endl;
  if (n == 7) cout << 116 << endl;
  if (n == 8) cout << 155 << endl;
  if (n == 9) cout << 198 << endl;
  if (n == 10) cout << 244 << endl;
  if (n == 11) cout << 292 << endl;
  if (n >= 12) cout << 292 + (n - 11) * 49 << endl;
  return 0;
}
