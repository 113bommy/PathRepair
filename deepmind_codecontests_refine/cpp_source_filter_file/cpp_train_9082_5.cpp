#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
void fio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fio();
  int t;
  cin >> t;
  while (t--) {
    long long l, r, m;
    cin >> l >> r >> m;
    long long lim = (r - l);
    int an = 0;
    for (long long a = l; a <= r; a++) {
      long long mm = m % a;
      long long mp = a - mm;
      if (mm <= lim && (mm != m)) {
        cout << a << " " << (l + mm) << " " << l << endl;
        an = 1;
        break;
      }
      if (mp <= lim && (-mm != m)) {
        cout << a << " " << (l) << " " << (l + mm) << endl;
        an = 1;
        break;
      }
    }
    if (an) continue;
  }
  return 0;
}
