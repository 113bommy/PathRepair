#include <bits/stdc++.h>
using namespace std;
int s[100010];
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      sum += s[i];
    }
    int k = 0, ans = 0;
    for (int i = 1; i <= n - 1; i++) {
      k += s[i];
      if (k == (sum - k)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
