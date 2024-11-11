#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, y, eva = 0, oda = 0, evb = 0, odb = 0;
  cin >> n >> m;
  long long a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0)
      eva++;
    else
      oda++;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (b[i] % 2 == 0)
      evb++;
    else
      odb++;
  }
  cout << min(eva, odb) + min(evb, oda) << endl;
  return 0;
}
