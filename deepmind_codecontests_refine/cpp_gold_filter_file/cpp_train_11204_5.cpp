#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long end = n;
  long long ans = 1;
  vector<long long> a(n + 1, 0);
  cout << ans << " ";
  for (int i = 0; i < n; i++) {
    a[v[i]] = 1;
    while (end > 0) {
      if (a[end] == 0) {
        break;
      } else {
        end--;
      }
    }
    cout << 1 + (i + 1 - (n - end)) << " ";
  }
  return 0;
}
