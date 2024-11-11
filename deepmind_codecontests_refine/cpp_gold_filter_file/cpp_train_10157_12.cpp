#include <bits/stdc++.h>
using namespace std;
int a[107], b[107], calc[107][107];
int func(int num1, int num2, int idx1, int idx2) {
  if (num1 < num2) return 2;
  if (num1 > num2) return 1;
  if (idx1 > idx2) return 2;
  return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] += a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      calc[i][j] += abs(func(a[i], a[j], i, j) - func(b[i], a[j], i, j));
      calc[i][j] += abs(func(a[j], b[i], j, i) - func(b[j], b[i], j, i));
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans += max(calc[i][j], calc[j][i]);
    }
  }
  cout << ans / 2 << endl;
  return 0;
}
