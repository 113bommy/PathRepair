#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int last[100000] = {0};
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int j = 1; j * j <= a; ++j) {
      if (a % j == 0 && i - last[j] > b) ++ans;
      if (a / j != j && a % j == 0 && i - last[a / j] > b) ++ans;
      if (a % j == 0) {
        last[j] = i;
        last[a / j] = i;
      }
    }
    cout << ans << "\n";
  }
}
