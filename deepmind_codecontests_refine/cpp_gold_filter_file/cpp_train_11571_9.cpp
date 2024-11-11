#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  if (n - v <= 1) {
    cout << n - 1 << endl;
    return 0;
  } else {
    int ans = v;
    for (int i = 2; i <= n - v; i++) ans += i;
    cout << ans << endl;
  }
}
