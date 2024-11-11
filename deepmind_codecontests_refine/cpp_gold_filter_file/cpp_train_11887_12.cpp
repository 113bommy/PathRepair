#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int arr[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  int flag = 1, ct = 1;
  for (int i = 1; i <= n; i++) {
    if (flag) {
      arr[i] = ct;
      arr[n + i] = ct + 1;
      flag = 0;
    } else {
      arr[i] = ct + 1;
      arr[n + i] = ct;
      flag = 1;
    }
    ct += 2;
  }
  cout << "YES\n";
  for (int i = 1; i <= 2 * n; i++) {
    cout << arr[i] << " ";
  }
}
