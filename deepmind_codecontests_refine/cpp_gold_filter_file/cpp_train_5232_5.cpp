#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long a[n], b[n], ind = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    long long ans = 3000000000000000000;
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
      long long x = i;
      for (int j = 0; j < n; j++) {
        if (x < n && b[x] == a[j]) x++;
      }
      ans = min(ans, n - (x - i));
    }
    cout << ans << '\n';
  }
}
