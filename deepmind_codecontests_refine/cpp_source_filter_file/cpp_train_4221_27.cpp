#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  while (n) {
    if (n % 8 == 0) ans++;
    n /= 8;
  }
  cout << ans;
}
