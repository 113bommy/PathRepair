#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, v1, v2;
char a[3000][3000];
bool ok;
int main() {
  cin >> n;
  a[1][1] = '+';
  k = 1;
  for (int w = 1; w <= n; w++) {
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++) a[i][j + k] = a[k - j + 1][k - i + 1];
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++) a[i + k][j] = a[k - i + 1][j];
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++)
        if (a[k - i + 1][j + k] == '+')
          a[i + k][j + k] = '*';
        else
          a[i + k][j + k] = '+';
    k *= 2;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) cout << a[i][j];
    cout << "\n";
  }
  cin >> n;
  return 0;
}
