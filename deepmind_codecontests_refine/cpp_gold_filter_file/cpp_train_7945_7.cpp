#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long int co = 0, r = 0, l = 0, u = 0, d = 0;
  for (long long int i = 0; i < n; i++) {
    r = 0, u = 0, l = 0, d = 0;
    for (long long int j = 0; j < n; j++) {
      if (a[i] == a[j] && b[i] > b[j]) {
        r++;
      } else if (a[i] == a[j] && b[i] < b[j]) {
        l++;
      }
      if (a[i] > a[j] && b[i] == b[j]) {
        d++;
      } else if (a[i] < a[j] && b[i] == b[j]) {
        u++;
      }
      if (l >= 1 && r >= 1 && d >= 1 && u >= 1) {
        co += 1;
        break;
      }
    }
  }
  cout << co << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
