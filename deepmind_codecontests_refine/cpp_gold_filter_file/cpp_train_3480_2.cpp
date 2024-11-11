#include <bits/stdc++.h>
using namespace std;
int k, a, b, v, ans;
int main() {
  cin >> k >> a >> b >> v;
  while (a > 0) {
    a -= min(k, b + 1) * v;
    b -= (k < b + 1 ? k - 1 : b);
    ans++;
  }
  cout << ans;
  return 0;
}
