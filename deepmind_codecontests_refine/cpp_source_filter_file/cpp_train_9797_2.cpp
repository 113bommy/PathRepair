#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, d = 0;
  cin >> n >> k;
  m = n % (2 * k + 1);
  if (m < (k + 1)) d = (k + 1) - m;
  cout << (n / (2 * k + 1)) + ((n % (2 * k + 1)) ? 1 : 0) << endl;
  for (int i = k + 1; i <= n + d; i += 2 * k + 1) cout << (i - d) << " ";
  cout << endl;
}
