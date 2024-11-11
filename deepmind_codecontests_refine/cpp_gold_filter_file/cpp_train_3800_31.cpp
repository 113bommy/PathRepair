#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, ans = 0;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    if (x % i == 0 && i * n >= x) ans++;
  }
  cout << ans << endl;
}
