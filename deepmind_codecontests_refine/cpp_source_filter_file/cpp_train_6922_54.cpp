#include <bits/stdc++.h>
using namespace std;
int main() {
  long long na, nb, a[100010], b[100010], k, m, i;
  cin >> na >> nb;
  cin >> k >> m;
  for (i = 1; i <= na; i++) cin >> a[i];
  for (i = 1; i <= nb; i++) cin >> b[i];
  for (i = 1; i <= nb; i++)
    if (b[i] > a[k]) {
      if (nb - i >= m)
        cout << "YES\n";
      else
        cout << "NO\n";
      break;
    }
  if (i == nb + 1) cout << "NO\n";
  return 0;
}
