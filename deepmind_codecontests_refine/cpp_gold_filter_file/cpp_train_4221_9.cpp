#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  cin >> n;
  while (n) {
    if (n % 8 == 1) ans++;
    n /= 8;
  }
  cout << ans << endl;
  return 0;
}
