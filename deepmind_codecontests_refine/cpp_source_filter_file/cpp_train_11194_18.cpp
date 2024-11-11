#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d[1005][1005];
int main() {
  cin >> n >> a >> b;
  if (n > a * b) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= a; i++) {
    if (b % 2 == 0 && i % 2 == 0) {
      for (int j = b; j >= 1; j--)
        if (c <= n) d[i][j] = c++;
    } else
      for (int j = 1; j <= b; j++)
        if (c <= n) d[i][j] = c++;
  }
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      if (j == b)
        cout << d[i][j] << endl;
      else
        cout << d[i][j] << " ";
  return 0;
}
