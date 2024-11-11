#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= 2 * n / 3; i++) cout << "0 " << i << '\n';
  for (int i = 2 * n / 3 + 1; i <= n; i++)
    cout << "3 " << 2 * (i - 2 * n / 3) << '\n';
  return 0;
}
