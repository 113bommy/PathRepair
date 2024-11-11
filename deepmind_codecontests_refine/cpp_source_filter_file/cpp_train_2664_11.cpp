#include <bits/stdc++.h>
using namespace std;
long long n, q, x, c1, c2;
int main() {
  cin.tie(0);
  std ::ios ::sync_with_stdio(false);
  string s = "ROYGBIV";
  int n, rem;
  cin >> n;
  rem = n - 7 * (n / 7);
  for (int i = 0; i < (int)(n / 7); i++) cout << s;
  s = "GBIV";
  for (int i = 0; i < rem; i++) cout << s[i];
  return 0;
}
