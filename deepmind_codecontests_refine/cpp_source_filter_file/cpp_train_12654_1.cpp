#include <bits/stdc++.h>
using namespace std;
long long int n, sum, sum2, arr[501][501];
bool check() {
  for (int i = 0; i < n; i++) sum += arr[0][i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) sum2 += arr[i][j];
    if (sum != sum2) return 0;
    sum2 = 0;
  }
  sum2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) sum2 += arr[j][i];
    if (sum != sum2) return 0;
    sum2 = 0;
  }
  sum2 = 0;
  for (int i = 0, j = 0; i < n; i++, j++) {
    sum2 += arr[i][j];
  }
  if (sum != sum2) return 0;
  sum2 = 0;
  for (int i = 0, j = n - 1; i < n; i++, j--) sum2 += arr[i][j];
  if (sum2 != sum) return 0;
  return 1;
}
int main() {
  cin >> n;
  if (n == 1) {
    cin >> n;
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  long long int z = -1, y;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (arr[i][j] == 0) {
        z = i;
        y = j;
        i = n;
        break;
      }
  long long int summ = 0, zz = 0;
  for (int i = 0; i < n; i++) zz += arr[z][i];
  if (z == 0)
    for (int i = 0; i < n; i++) summ += arr[1][i];
  else
    for (int i = 0; i < n; i++) summ += arr[0][i];
  arr[z][y] = summ - zz;
  if (!check() || summ - zz == 0)
    cout << -1 << endl;
  else
    cout << summ - zz << endl;
  return 0;
}
