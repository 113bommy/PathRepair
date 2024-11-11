#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, h, m, a[102], hasil, cek = 0, t;
  cin >> n >> s;
  s = s * 2 + 2;
  t = s / 2;
  for (int i = 1; i <= n; i++) {
    cin >> h >> m;
    a[i] = 60 * h + m;
  }
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    if ((a[i] - a[i - 1]) >= s || i == 1 && a[i] - a[i - 1] >= t) {
      if (i == 1)
        hasil = 0;
      else
        hasil = a[i - 1] + s / 2;
      cek = 1;
      break;
    }
  }
  if (!cek) {
    hasil = a[n] + s / 2;
  }
  cout << hasil / 60 << " " << hasil % 60 << endl;
}
