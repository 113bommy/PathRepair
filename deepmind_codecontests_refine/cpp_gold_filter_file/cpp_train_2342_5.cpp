#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++])
    ;
  cout << a[2] - a[1] << " " << a[n] - a[1] << '\n';
  for (int i = 2; i < n; i++) {
    cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << " "
         << max(a[n] - a[i], a[i] - a[1]);
    cout << '\n';
  }
  cout << a[n] - a[n - 1] << " " << a[n] - a[1] << '\n';
}
