#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) continue;
    if ((a[i] == a[i - 1]) || (a[i] == 2 && a[i - 1] == 3) ||
        (a[i] == 3 && a[i - 1] == 2)) {
      cout << "Infinitive";
      return 0;
    }
    if (a[i] == 2 && a[i - 1] == 1 || a[i] == 1 && a[i - 1] == 2) ans += 3;
    if (a[i] == 1 && a[i - 1] == 3 || a[i] == 3 && a[i - 1] == 1) ans += 4;
    if (i >= 3 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) ans--;
  }
  cout << "Finite\n" << ans;
}
