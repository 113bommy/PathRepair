#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, m;
  int l, r, x;
  cin >> n >> h >> m;
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) arr[i] = -1;
  for (int j = 0; j < m; j++) {
    cin >> l >> r >> x;
    for (int i = l; i < r + 1; i++)
      if (arr[i] > x || arr[i] == -1) arr[i] = x;
  }
  int sum = 0;
  for (int i = 1; i < n + 1; i++) {
    if (arr[i] == -1)
      sum += h * h;
    else
      sum += arr[i] * arr[i];
  }
  cout << sum << endl;
  return 0;
}
