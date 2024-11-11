#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int cnt = 0;
  while (a >= 0) {
    a -= v * (min(k - 1, b) + 1);
    b -= min(k - 1, b);
    cnt++;
  }
  cout << cnt;
  return 0;
}
