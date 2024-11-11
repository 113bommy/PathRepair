#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j, ans = 0, maxi;
  cin >> n;
  int a[105];
  for (i = 1; i <= n; i++) cin >> a[i];
  a[0] = 0;
  a[(n + 1)] = 1001;
  for (i = 0; i <= (n + 1); i++) {
    for (j = i + 1; j <= (n + 1); j++) {
      if ((a[j] - j) == (a[i] - i)) {
        ans = j - i - 1;
        maxi = max(maxi, ans);
      }
    }
  }
  cout << maxi;
  return 0;
}
