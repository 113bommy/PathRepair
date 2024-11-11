#include <bits/stdc++.h>
using namespace std;
long long int arr[4005][4005];
long long int brr[4005], crr[4005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    for (long long int i = 0; i < m; i++) {
      long long int a, b;
      cin >> a >> b;
      arr[a][b] = 1;
      arr[b][a] = 1;
      brr[a]++;
      brr[b]++;
    }
    long long int ans = INT_MAX;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = i + 1; j <= n; j++) {
        if (arr[i][j] == 1) {
          for (long long int k = j + 1; k <= n; k++) {
            if (arr[i][k] == 1 && arr[j][k] == 1) {
              long long int temp = brr[i] + brr[j] + brr[k];
              ans = min(ans, temp);
            }
          }
        }
      }
    }
    if (ans == INT_MAX)
      cout << "-1" << endl;
    else
      cout << ans - 6 << endl;
  }
  return 0;
}
