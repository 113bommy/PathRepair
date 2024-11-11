#include <bits/stdc++.h>
using namespace std;
int n;
char cad[2005][2005];
int a[2005][2005];
int fila[2005], col[2005];
int ch[2005][2005];
int main() {
  cin >> n;
  gets(cad[0]);
  for (int i = 0; i < n; i++) gets(cad[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = cad[i][j] - '0';
  int res = 0;
  for (int x = 1; x < n; x++) {
    for (int i = n - x; i < n; i++)
      if ((fila[i] ^ col[i - n + x]) != a[i][i - n + x])
        ch[i][i - n + x] = 1, fila[i] ^= 1, col[i - n + x] ^= 1, res++;
  }
  vector<int> v1(n, 0);
  for (int i = 0; i < n; i++) v1[i] = fila[i] ^ col[i];
  memset(fila, 0, sizeof(fila));
  memset(col, 0, sizeof(col));
  for (int x = 1; x < n; x++) {
    for (int i = n - x; i < n; i++)
      if ((fila[i - n + x] ^ col[i]) != a[i - n + x][i])
        fila[i - n + x] ^= 1, col[i] ^= 1, res++;
  }
  vector<int> v2(n, 0);
  for (int i = 0; i < n; i++) v2[i] = fila[i] ^ col[i] ^ v1[i];
  for (int i = 0; i < n; i++)
    if (v2[i] != a[i][i]) res++;
  cout << res << endl;
}
