#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  int ans;
  if (a % 2) {
    ans = (a + 1) / 2;
  } else {
    ans = n / 2 - a / 2 + 1;
  }
  cout << ans << endl;
  return 0;
}
