#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  ;
  string a;
  cin >> a;
  long long n = a.length();
  long long i, j, k;
  long long ans = 0, f;
  long long pass[n + 2];
  for (i = 0; i <= n; i++) pass[i] = 0;
  for (i = 0; i < n; i++) {
    f = 0;
    for (j = i + 1; j < n; j++) {
      k = j - i;
      if (j + k < n && a[j] == a[i] && a[j + k] == a[i]) {
        f = 1;
        break;
      }
    }
    if (f) {
      pass[i] = n - j - k;
    }
  }
  for (i = n - 2; i >= 0; i--) {
    pass[i] = fmax(pass[i], pass[i + 1]);
    ans += pass[i];
  }
  cout << ans;
  return 0;
}
