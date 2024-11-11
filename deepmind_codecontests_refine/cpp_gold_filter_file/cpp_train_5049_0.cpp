#include <bits/stdc++.h>
using namespace std;
long long a[200002];
long long Left[200002];
long long Right[200002];
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  memset(Left, 0, sizeof Left);
  memset(Right, 0, sizeof Right);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    Left[i] = Left[i - 1] | a[i];
  }
  for (int i = n; i >= 1; i--) {
    Right[i] = Right[i + 1] | a[i];
  }
  long long ans = 0;
  for (int pos = 1; pos <= n; pos++) {
    long long tem = a[pos];
    for (int i = 1; i <= k; i++) {
      tem = tem * x;
    }
    ans = max(ans, Left[pos - 1] | tem | Right[pos + 1]);
  }
  cout << ans << endl;
  return 0;
}
