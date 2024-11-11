#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, k = 0;
  cin >> n >> a >> b >> c;
  while ((n + k) % 4 != 0) k++;
  if (k == 0) cout << 0, exit(0);
  if (k == 1) cout << min(a, min(3 * c, b + c));
  ;
  if (k == 2) cout << min(min(a * 2, b), c);
  if (k == 3) cout << min(min(a * 3, a + b), c);
  return 0;
}
