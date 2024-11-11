#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long i, j, k, l, m, n;
  cin >> n;
  unsigned long long ans = 0;
  for (i = 1; i <= n; i++) ans = ans + (1 << i);
  cout << ans << endl;
}
