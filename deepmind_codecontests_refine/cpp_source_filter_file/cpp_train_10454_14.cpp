#include <bits/stdc++.h>
using namespace std;
long long int x[51];
long long int y[51];
long long int xy_kol[51];
long long int yx_kol[51];
long long int yy_kol[51];
long long int k, n, m;
void go(int i, int j, int xy, int yx, int yy) {
  string a(n, 'Z');
  string b(m, 'Z');
  if (xy) a.back() = 'A', b[0] = 'C';
  if (yx) b.back() = 'A', a[0] = 'C';
  if (yy) b.back() = 'A', b[0] = 'C';
  for (int q = 0 + (a[0] != 'Z'); i--; q += 2) {
    a[q] = 'A';
    a[q + 1] = 'C';
  }
  for (int q = 0 + (b[0] != 'Z'); j--; q += 2) {
    b[q] = 'A';
    b[q + 1] = 'C';
  }
  cout << a << endl;
  cout << b << endl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  x[1] = 1;
  x[2] = 0;
  for (int i = 3; i <= 50; i++) x[i] = x[i - 1] + x[i - 2];
  y[1] = 0;
  y[2] = 1;
  for (int i = 3; i <= 50; i++) y[i] = y[i - 1] + y[i - 2];
  xy_kol[3] = 1;
  xy_kol[4] = 1;
  for (int i = 5; i <= 50; i++) xy_kol[i] = xy_kol[i - 1] + xy_kol[i - 2];
  for (int i = 4; i <= 50; i++)
    yx_kol[i] = yx_kol[i - 1] + yx_kol[i - 2] + (i - 1) % 2;
  for (int i = 5; i <= 50; i++)
    yy_kol[i] = yy_kol[i - 1] + yy_kol[i - 2] + (i) % 2;
  long long int total;
  cin >> k >> total >> n >> m;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j <= m / 2; j++) {
      for (int xy = 0; xy <= 1; xy++) {
        for (int yx = 0; yx <= 1; yx++) {
          for (int yy = xy * yx; yy <= 1; yy++) {
            if (i * 2 + xy + yx > n) continue;
            if (j * 2 + xy + yx + (2 * yy - xy - yx) > m) continue;
            if (i * x[k] + j * y[k] + xy * xy_kol[k] + yx * yx_kol[k] +
                    yy * yy_kol[k] ==
                total) {
              go(i, j, xy, yx, yy);
            }
          }
        }
      }
    }
  }
  cout << "Happy new year!";
  return 0;
}
