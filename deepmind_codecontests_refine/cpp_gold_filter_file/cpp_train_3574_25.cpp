#include <bits/stdc++.h>
using namespace std;
int main() {
  int s[10000], ind = 0, n, x, varmi = 0, i, j, tut[10000], a, b;
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == x) varmi = 1;
  }
  if (varmi == 0) n++, s[n] = x;
  varmi = 1 - varmi;
  sort(s + 1, s + n + 1);
  for (i = 1; i <= n; i++) {
    if (s[i] == x) {
      a = i - 1;
      b = n - i;
      ind++;
      if (1) {
        if (a >= b)
          tut[ind] = a - b;
        else
          tut[ind] = b - a - 1;
      } else {
        if (b >= a)
          tut[ind] = b - a;
        else
          tut[ind] = a - b;
      }
    }
  }
  sort(tut + 1, tut + ind + 1);
  cout << tut[1] + varmi;
}
