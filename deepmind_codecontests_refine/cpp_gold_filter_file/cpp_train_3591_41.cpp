#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (n == 1) {
    cout << 1;
    exit(0);
  }
  int ans = 0;
  if (a != 0) {
    ans = a - 1;
  }
  if (n - (a + 1) + 1 > ans && a + 1 <= n) {
    ans = a + 1;
  }
  cout << ans;
}
