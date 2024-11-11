#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100 + 10;
int n, m;
int arr[N][N];
long long Sum;
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> arr[i][j];
  return;
}
void check(int &i, int &j) {
  if (max(arr[i - 1][j], arr[i][j - 1]) >= arr[i][j]) {
    cout << -1 << endl;
    exit(0);
  }
  return;
}
void solve() {
  for (int i = n; i > 0; i--)
    for (int j = n; j > 0; j--) {
      if (arr[i][j])
        Sum += arr[i][j];
      else {
        arr[i][j] = min(arr[i + 1][j], arr[i][j + 1]) - 1;
        Sum += arr[i][j];
      }
      check(i, j);
    }
  return;
}
int main() {
  input();
  solve();
  cout << Sum << endl;
  return 0;
}
