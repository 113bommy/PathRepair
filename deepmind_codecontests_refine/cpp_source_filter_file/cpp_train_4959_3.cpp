#include <bits/stdc++.h>
using namespace std;
int m, mm, s[1010], g;
int gcd(int a, int b) {
  while (b) {
    int aux = a % b;
    a = b;
    b = aux;
  }
  return a;
}
int main() {
  cin >> m;
  mm = 1000000000;
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
    mm = min(mm, s[i]);
  }
  g = s[0];
  for (int i = 1; i < m; ++i) g = gcd(g, s[i]);
  if (mm != g) {
    cout << -1 << endl;
    return 0;
  }
  cout << 2 * m - 1 << endl << s[0];
  for (int i = 1; i < m; ++i) cout << " " << m << " " << s[i];
  cout << endl;
  return 0;
}
