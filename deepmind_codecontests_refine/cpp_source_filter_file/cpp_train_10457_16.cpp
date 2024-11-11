#include <bits/stdc++.h>
using namespace std;
string s;
int a[251], n, i, j, k, l, r, nom, zn;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> l >> r;
  cin >> s;
  n = s.size();
  if ((n < l * k) || (n > r * k)) {
    cout << "No solution" << '\n';
    return 0;
  }
  for (i = 1; i <= k; i++) a[i] = l;
  zn = n - l * k;
  for (i = 1; i <= k; i++)
    if (zn - (r - l) >= 0) {
      zn -= r - l;
      a[i] = r;
    } else {
      a[i] += r - l - zn;
      break;
    }
  for (i = 1; i <= k; i++) {
    for (j = nom; j < nom + a[i]; j++) cout << s[j];
    cout << '\n';
    nom += a[i];
  }
  return 0;
}
