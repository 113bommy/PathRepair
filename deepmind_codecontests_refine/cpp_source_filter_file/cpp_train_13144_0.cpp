#include <bits/stdc++.h>
using namespace std;
const int MIN_N = -(1e9);
int main() {
  int t, i, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    int a[n + 1];
    long long ans[3 * n + 2];
    long long sum = 0;
    memset(ans, 0, sizeof(ans));
    a[1] = int(s[0] - '0');
    for (i = 2; i <= n; i++) {
      a[i] = a[i - 1] + int(s[i - 1] - '0');
    }
    ans[2 * n]++;
    for (i = 1; i <= n; i++) {
      ans[a[i] - i + 2 * n]++;
    }
    for (i = 0; i <= 3 * n; i++) {
      if (ans[i] > 1) sum += ans[i] * ((ans[i] - 1) / 2);
    }
    cout << sum << endl;
  }
  return 0;
}
