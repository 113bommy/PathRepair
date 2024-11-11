#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<int>> arr(n + 1, vector<int>(n + 1));
  int num = n * n, sum = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= k; j--) {
      arr[i][j] = num--;
      if (j == k) {
        sum += arr[i][j];
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = k - 1; j >= 1; j--) {
      arr[i][j] = num--;
    }
  }
  cout << sum << '\n';
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
