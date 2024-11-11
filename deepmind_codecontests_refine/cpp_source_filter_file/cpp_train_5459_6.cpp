#include <bits/stdc++.h>
using namespace std;
int n, ans, k;
int main() {
  cin >> n;
  k = k;
  if (n % 2 == 1)
    ans = k * (k + 1);
  else
    ans = k * k;
  cout << ans << endl;
  for (int i = 1; i <= k; i++)
    for (int j = k + 1; j <= n; j++) cout << i << " " << j << endl;
  return 0;
}
