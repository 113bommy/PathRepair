#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  while (cin >> n >> a) {
    if (a % 2 == 0) a = n + 1 - a;
    int ans = (a + 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
