#include <bits/stdc++.h>
using namespace std;
int main() {
  long n = 0, i = 0, a = 0, max = 0;
  long mas[3][100001] = {0};
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a;
    if (a > max) max = a;
    {
      if (mas[0][a] == 0) {
        mas[0][a] = i;
        continue;
      }
      if (mas[1][a] == 0) {
        mas[1][a] = mas[0][a];
        mas[0][a] = i;
        mas[2][a] = i - mas[1][a];
        continue;
      }
    }
    if ((mas[2][a]) == (i - mas[0][a])) {
      mas[1][a] = mas[0][a];
      mas[0][a] = i;
    } else
      mas[2][a] = -1;
  }
  long k = 0;
  for (i = 1; i <= n; ++i)
    if (mas[2][i] != -1 && mas[0][i] > 0) ++k;
  cout << k << endl;
  for (i = 1; i <= max; ++i)
    if (mas[2][i] != -1 && mas[0][i] > 0) cout << i << " " << mas[2][i] << endl;
  return 0;
}
