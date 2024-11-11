#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void yash() {
  int n;
  cin >> n;
  int arr[101][101] = {0};
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j <= c; j++)
      for (int k = b; k <= d; k++) arr[j][k]++;
  }
  int sum = 0;
  for (int i = 1; i < 5; i++)
    for (int j = 1; j < 5; j++) sum += arr[i][j];
  cout << sum << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  yash();
  return 0;
}
