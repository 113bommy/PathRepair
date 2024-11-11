#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  int l = max(m, n);
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      if (i * i + j == n && i + j * j == m) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
