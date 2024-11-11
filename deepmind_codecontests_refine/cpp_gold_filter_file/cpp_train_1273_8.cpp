#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, i, ans = 0;
  cin >> n;
  long long a[n], b[n], c[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) c[i] = a[i] - b[i];
  sort(c, c + n);
  for (i = 0; i < n; i++) {
    long long pos = upper_bound(c + i + 1, c + n, -c[i]) - c;
    ans += n - (pos);
  }
  cout << ans << endl;
  return 0;
}
