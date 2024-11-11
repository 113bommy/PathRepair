#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, s, i, j, k, st = 0, st1 = 0, st2 = 0, tam, h = 0;
  cin >> n >> s;
  array<long long, 4> tab[n];
  for (i = 0; i < n; i++) {
    cin >> tab[i][3] >> tab[i][1] >> tab[i][2];
    tab[i][0] = tab[i][1] - tab[i][2];
    st += tab[i][3];
    tab[i][1] > tab[i][2] ? st1 += tab[i][3] : st2 += tab[i][3];
    tab[i][1] > tab[i][2] ? h += tab[i][3] * tab[i][1]
                          : h += tab[i][3] * tab[i][2];
  }
  if (st1 % s != 0 && st2 % s != 0) {
    sort(tab, tab + n);
    long long sto2 = st2 - (st2 % s), sts = st % s;
    unsigned long long dh1 = 0, dh2 = 0;
    if (sts == 0) sts = s;
    for (i = 0; i < n; i++) {
      if (sto2 - tab[i][3] < 0) {
        if (sts > 0) {
          if (tab[i][2] > tab[i][1] && sto2 > 0) {
            dh1 -= (tab[i][3] - sto2) * tab[i][0];
            sts -= (tab[i][3] - sto2);
          } else if (tab[i][2] > tab[i][1] && tab[i][3] <= sts) {
            dh1 -= tab[i][3] * tab[i][0];
            sts -= tab[i][3];
          } else if (tab[i][2] > tab[i][1]) {
            dh1 -= sts * tab[i][0];
            sts = 0;
          } else if (tab[i][1] == tab[i][2])
            sts -= tab[i][3];
          else if (tab[i][1] > tab[i][2] && sts - tab[i][3] > 0) {
            dh2 += tab[i][3] * tab[i][0];
            sts -= tab[i][3];
          } else {
            dh2 += sts * tab[i][0];
            sts = 0;
          }
        }
        sto2 -= tab[i][3];
      } else
        sto2 -= tab[i][3];
    }
    h -= min(dh1, dh2);
  }
  cout << h << endl;
  return 0;
}
