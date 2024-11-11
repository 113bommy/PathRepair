#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t, j, i, n, x, a, b, c, otv, k, q, p, z, l, r;
  cin >> t;
  b = 0;
  for (j = 0; j < t; ++j) {
    cin >> n >> q;
    vector<long long int> all(n + 1);
    vector<long long int> raz(n + 1);
    all[0] = 0;
    otv = 0;
    for (i = 1; i <= n; ++i) {
      cin >> all[i];
      raz[i] = all[i] - all[i - 1];
      otv += max(b, raz[i]);
    }
    cout << otv << endl;
    for (i = 0; i < q; ++i) {
      cin >> l >> r;
      if (r == l)
        cout << otv;
      else {
        if (r == l + 1) {
          otv -= max(b, raz[l]) + max(b, raz[l + 1]);
          if (r < n) {
            otv -= max(b, raz[r + 1]);
          }
          x = all[l];
          all[l] = all[r];
          all[r] = x;
          raz[l] = all[l] - all[l - 1];
          raz[l + 1] = all[l + 1] - all[l];
          if (r < n) {
            raz[r + 1] = all[r + 1] - all[r];
            otv += max(b, raz[l]) + max(b, raz[l + 1]) + max(b, raz[r + 1]);
          } else
            otv += max(b, raz[l]) + max(b, raz[l + 1]);
        } else {
          otv -= max(b, raz[l]) + max(b, raz[l + 1]) + max(b, raz[r]);
          if (r < n) {
            otv -= max(b, raz[r + 1]);
          }
          x = all[l];
          all[l] = all[r];
          all[r] = x;
          raz[l] = all[l] - all[l - 1];
          raz[l + 1] = all[l + 1] - all[l];
          raz[r] = all[r] - all[r - 1];
          if (r < n) {
            raz[r + 1] = all[r + 1] - all[r];
            otv += max(b, raz[l]) + max(b, raz[l + 1]) + max(b, raz[r + 1]) +
                   max(b, raz[r]);
          } else
            otv += max(b, raz[l]) + max(b, raz[l + 1]) + max(b, raz[r]);
        }
        cout << otv << endl;
      }
    }
  }
  return 0;
}
