#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[51];
long long b[51];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  long long ans = -9223372036854775807;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] * b[i] > ans) {
        ans = a[i] * b[j];
        cnt = i;
      }
    }
  }
  ans = -9223372036854775807;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == cnt) break;
      ans = max(ans, a[i] * b[j]);
    }
  }
  cout << ans << endl;
}
