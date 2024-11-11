#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  string a;
  ll i, j, k, l, c, kr = 0, kb = 0, ky = 0, kg = 0, r = 0, b = 0, y = 0, g = 0;
  cin >> a;
  l = a.size();
  for (i = 0; i < l; i += 4) {
    k = 1;
    for (j = i; j < i + 4; j++) {
      if (a[j] == 'R') {
        kr = k;
      } else if (a[j] == 'B') {
        kb = k;
      } else if (a[j] == 'Y') {
        ky = k;
      } else if (a[j] == 'G') {
        kg = k;
      }
      k++;
    }
  }
  for (i = 0; i < l; i += 4) {
    k = 1;
    for (j = i; j < i + 4; j++) {
      if (a[j] == '!') {
        if (k == kr) {
          r++;
        } else if (k == kb) {
          b++;
        } else if (k == ky) {
          y++;
        } else if (k == kg) {
          g++;
        }
      }
      k++;
    }
  }
  cout << r << " " << b << " " << y << " " << g << endl;
  return 0;
}
