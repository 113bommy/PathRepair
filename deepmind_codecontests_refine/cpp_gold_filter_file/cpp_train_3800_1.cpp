#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 1; i <= a; i++) {
    if (b / i > a) continue;
    if (b % i == 0) ans++;
  }
  cout << ans;
  return 0;
}
