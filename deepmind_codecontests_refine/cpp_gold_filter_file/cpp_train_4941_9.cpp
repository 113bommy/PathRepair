#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, ans = 0;
  cin >> n;
  i = 0;
  while (1) {
    i++;
    if (3 * (i * (i + 1) / 2) > n + i) break;
    if ((n + i) % 3 == 0) ans++;
  }
  cout << ans;
}
