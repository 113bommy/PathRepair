#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int mod = 1000000007;
char s[N];
long long a[N], b[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m, t;
  cin >> t;
  for (int j = 1; j <= t; j++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
      printf("%lld ", a[i]);
    }
    puts("");
    for (int i = 1; i <= n; i++) {
      printf("%lld ", b[i]);
    }
    puts("");
  }
  return 0;
}
