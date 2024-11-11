#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1000000007;
const long double PI = acos(-1);
int t, m, x;
char com[100];
int a[N], b[N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int i, j, n = 0, z, identifier = 0;
  cin >> t >> m;
  for (i = 1; (1 < 0 ? i >= t : i <= t); i += 1) {
    cin >> com;
    if (com[0] == 'a') {
      cin >> x;
      for (j = 1; (1 < 0 ? j >= m : j <= m); j += 1)
        if (a[j] == 0) {
          for (z = j; (1 < 0 ? z >= m : z <= m); z += 1)
            if (a[z]) break;
          if (z - j >= x) {
            ++identifier;
            for (z = 1; (1 < 0 ? z >= x : z <= x); z += 1)
              a[z + j - 1] = identifier;
            cout << identifier << '\n';
            break;
          }
        }
      if (j == m + 1) cout << "NULL\n";
    } else if (com[0] == 'e') {
      bool ok = 0;
      cin >> x;
      for (j = 1; (1 < 0 ? j >= m : j <= m); j += 1)
        if (a[j] == x) {
          ok = 1;
          a[j] = 0;
        }
      if (!ok) cout << "ILLEGAL_ERASE_ARGUMENT\n";
    } else if (com[0] == 'd') {
      n = 0;
      for (j = 1; (1 < 0 ? j >= m : j <= m); j += 1)
        if (a[j]) b[++n] = a[j];
      for (j = 1; (1 < 0 ? j >= n : j <= n); j += 1) a[j] = b[j];
      for (j = n + 1; (1 < 0 ? j >= m : j <= m); j += 1) a[j] = 0;
    }
  }
  return 0;
}
