#include <bits/stdc++.h>
using namespace std;
const int EE = 100010;
int a[EE];
int t[EE];
long long n, sum, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  ans = sum;
  for (int i = n; i >= 1; i--) {
    t[i] = t[i + 1] + a[i];
  }
  for (int i = n; i >= 1; i--) {
    a[i] += a[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    t[i] = min(t[i], t[i + 1]);
  }
  for (int i = 0; i <= n; i++) {
    ans = max(ans, sum - 2 * (a[i] + t[i + 1]));
  }
  cout << ans;
  return 0;
}
