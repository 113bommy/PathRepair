#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int r[n + 1], c[m + 1], posr[n + 1], posc[m + 1];
  fill(posr, posr + n + 1, -1);
  fill(posc, posc + m + 1, -1);
  fill(c, c + m + 1, 0);
  fill(r, r + n + 1, 0);
  for (int i = 0; i < k; i++) {
    long long int num, typ, val;
    cin >> typ >> num >> val;
    if (typ == 1) {
      r[num] = val;
      posr[num] = i;
    } else {
      c[num] = val;
      posc[num] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (posr[i] > posc[j]) {
        cout << r[i] << " ";
      } else {
        cout << c[j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
