#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m[47][47];
  cin >> n;
  int p = 1, q = 2;
  memset(m, 0, sizeof(m));
  for (int i = 0; i <= n / 2; i++)
    for (int j = n / 2 - i; j <= n / 2 + i; j++) m[i][j] = p, p += 2;
  for (int i = n / 2 + 1; i < n; i++)
    for (int j = i - n / 2; j < -i + 3 * n / 2; j++) m[i][j] = p, p += 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (m[i][j] == 0) m[i][j] = q, q += 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << m[i][j] << " ";
    cout << endl;
  }
  return 0;
}
