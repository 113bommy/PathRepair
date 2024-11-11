#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t, c;
  cin >> n >> t >> c;
  long long int cnt = 0;
  long long int ar[n + 1];
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] <= t) cnt++;
    if (ar[i] > t) {
      if (cnt >= c) {
        ans = ans + cnt - c + 1;
      }
      cnt = 0;
    }
  }
  if (cnt >= c) ans = ans + c - 1;
  cout << ans;
}
