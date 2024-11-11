#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n + 5];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n > m) {
    cout << 0 << "\n";
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans *= abs(arr[i] - arr[j]);
      ans = ans % m;
    }
  }
  cout << ans % m << endl;
}
