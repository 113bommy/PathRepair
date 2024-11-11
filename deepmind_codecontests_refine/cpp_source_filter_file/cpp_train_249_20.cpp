#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e3 + 5;
const long long Mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f;
int sg[35000][40] = {};
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  for (int i = 13334; i >= 1; i--)
    for (int j = 31; j >= 1; j--) sg[i][j] = 1;
  for (int i = 13333; i >= 1; i--)
    for (int j = 30; j >= 1; j--) {
      long long x = 1;
      for (int k = 1; k <= j && x < n; k++) x *= i;
      if (x < n) sg[i][j] = 1 - (sg[i + 1][j] & sg[i][j + 1]);
    }
  if (a == 1 && pow(a + 1, b) + 1e-8 > n)
    cout << "Missing" << endl;
  else if (b == 1 && a * a >= n) {
    if ((n - a + 1) & 1)
      cout << "Masha" << endl;
    else
      cout << "Stas" << endl;
  } else if (sg[a][b])
    cout << "Masha" << endl;
  else
    cout << "Stas" << endl;
  return 0;
}
