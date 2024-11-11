#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int a, b;
  cin >> a >> b;
  int arr[n + 1], brr[m + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= m; i++) {
    cin >> brr[i];
  }
  if (arr[a] > brr[m - b + 1]) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
  return 0;
}
