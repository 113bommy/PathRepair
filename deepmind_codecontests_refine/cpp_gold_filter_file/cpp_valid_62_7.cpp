#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long mod = (long long)1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (arr[n - 1] == 0) {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
    cout << '\n';
  } else if (arr[0] == 1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << '\n';
  } else {
    int x = 0;
    for (int i = 0; i < n - 1; i++)
      if (arr[i] == 0 && arr[i + 1] == 1) {
        x = i + 1;
        break;
      }
    for (int i = 1; i <= x; i++) cout << i << " ";
    cout << n + 1 << " ";
    for (int i = x + 1; i <= n; i++) cout << i << " ";
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
