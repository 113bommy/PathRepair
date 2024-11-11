#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans;
  if (m % 2 == 1)
    ans = min(m / 2, n - m / 2);
  else
    ans = min(m / 2 - 1, n - m / 2 + 1);
  if (ans > 0)
    cout << ans;
  else
    cout << "0";
  return 0;
}
