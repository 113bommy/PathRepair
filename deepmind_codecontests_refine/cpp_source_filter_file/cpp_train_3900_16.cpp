#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int arr[n][n];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) cin >> arr[i][j];
  }
  map<long long int, long long int> m1, m2;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (!m1.count(i + j))
        m1[i + j] = arr[i][j];
      else
        m1[i + j] += arr[i][j];
      if (!m2.count(i - j))
        m2[i - j] = arr[i][j];
      else
        m2[i - j] += arr[i][j];
    }
  }
  long long int ans1 = 0, ans2 = 0, x1, y1, x2, y2;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      long long int p = m1[i + j] + m2[i - j] - arr[i][j];
      if ((i + j) % 2 && p > ans1) {
        ans1 = p;
        x1 = i + 1;
        y1 = j + 1;
      }
      if ((i + j) % 2 == 0 && p > ans2) {
        ans2 = p;
        x2 = i + 1;
        y2 = j + 1;
      }
    }
  }
  cout << ans1 + ans2 << '\n';
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
}
