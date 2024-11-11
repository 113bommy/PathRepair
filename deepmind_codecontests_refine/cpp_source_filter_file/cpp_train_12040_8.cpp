#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
  int sum = 1;
  if (n < 10) return n;
  if (n >= 10) {
    while (n) {
      if (n % 10 != 0) {
        sum *= (n % 10);
      }
      n /= 10;
    }
    return solve(sum);
  }
}
int arr[11][1000005] = {};
int arr2[1000005] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 10; i <= 100; i++) {
    arr2[i] = solve(i);
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 100; j++) {
      arr[i][j] = arr[i][j - 1] + (arr2[j] == i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int ans = arr[k][r] - arr[k][l - 1];
    cout << ans << endl;
  }
  return 0;
}
