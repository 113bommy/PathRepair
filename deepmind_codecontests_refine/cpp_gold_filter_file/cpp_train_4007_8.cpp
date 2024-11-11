#include <bits/stdc++.h>
using namespace std;
long long int arr[1005][1005];
int main() {
  long long int n, m, k, a, b, ans = 0, o = 0;
  cin >> n >> m >> k;
  for (long long int i = 0; i < n + 1; i++) {
    fill(arr[i], arr[i] + m + 1, 0);
  }
  for (long long int i = 0; i < k; i++) {
    cin >> a >> b;
    if (arr[a + 1][b] == 1 && arr[a][b + 1] == 1 && arr[a + 1][b + 1] == 1) {
      if (o == 0) {
        o = 1;
        ans = i + 1;
      }
    } else if (arr[a][b - 1] == 1 && arr[a + 1][b] == 1 &&
               arr[a + 1][b - 1] == 1) {
      if (o == 0) {
        o = 1;
        ans = i + 1;
      }
    } else if (arr[a - 1][b] == 1 && arr[a][b - 1] == 1 &&
               arr[a - 1][b - 1] == 1) {
      if (o == 0) {
        o = 1;
        ans = i + 1;
      }
    } else if (arr[a - 1][b] == 1 && arr[a][b + 1] == 1 &&
               arr[a - 1][b + 1] == 1) {
      if (o == 0) {
        o = 1;
        ans = i + 1;
      }
    }
    arr[a][b] = 1;
  }
  cout << ans << endl;
  return 0;
}
