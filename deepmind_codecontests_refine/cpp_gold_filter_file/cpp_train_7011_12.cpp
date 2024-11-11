#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i <= max(a, b); i++) {
    for (int j = 0; j <= max(a, b); j++) {
      if (i * i + j == a) {
        if (j * j + i == b) {
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
