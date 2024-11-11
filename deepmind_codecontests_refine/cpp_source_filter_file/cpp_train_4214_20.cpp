#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a, k, l, h, m, t, aa[10];
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      cout << "YES" << endl;
      cout << 1 << endl << 1 << endl << 3 << endl << 3 << endl;
    } else if (n == 1) {
      cin >> i;
      cout << "YES" << endl;
      cout << i << endl << 3 * i << endl << 3 * i << endl;
    } else if (n == 2) {
      cin >> i >> j;
      if (i > j) {
        t = i;
        i = j;
        j = t;
      }
      if ((4 * i - j) > 0) {
        cout << "YES" << endl << 3 * i << endl << 4 * i - j << endl;
      } else
        cout << "NO" << endl;
    } else if (n == 3) {
      cin >> i >> j >> k;
      m = 1;
      l = 0;
      while (m < 501) {
        memset(aa, 0, sizeof(aa));
        aa[0] = i;
        aa[1] = j;
        aa[2] = k;
        aa[3] = m;
        sort(aa + 0, aa + 4);
        if ((m + i + j + k) % 4 == 0 && (aa[1] + aa[2]) % 2 == 0)
          if ((m + i + j + k) / 4 == (aa[1] + aa[2]) / 2 &&
              (aa[3] - aa[0]) == (m + i + j + k) / 4) {
            l = 1;
            break;
          }
        m++;
      }
      if (l == 1)
        cout << "YES" << endl << m << endl;
      else
        cout << "NO" << endl;
    } else if (n == 4) {
      k = 0;
      memset(aa, 0, sizeof(aa));
      for (a = 0; a < 4; a++) {
        cin >> aa[a];
        k += aa[a];
      }
      sort(aa + 0, aa + 4);
      if (k % 4 == 0 && (aa[1] + aa[2]) % 2 == 0)
        if ((aa[1] + aa[2]) / 2 == (aa[3] - aa[0]) && (aa[3] - aa[0]) == k / 4)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
    }
  }
  return 0;
}
