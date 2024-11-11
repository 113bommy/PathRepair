#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  int n, m;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++) cin >> arr[i];
  sort(arr, arr + m);
  if (arr[0] == 1 || arr[m - 1] == n)
    cout << "NO";
  else {
    bool flag = true;
    for (int i = 0; i < m - 2; i++) {
      if ((arr[i + 2] - arr[i + 1] == 1) && (arr[i + 1] - arr[i] == 1)) {
        flag = false;
        cout << "NO";
        break;
      }
    }
    if (flag) cout << "YES";
  }
}
