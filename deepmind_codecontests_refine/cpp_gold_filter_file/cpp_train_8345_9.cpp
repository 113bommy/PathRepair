#include <bits/stdc++.h>
using namespace std;
char cit[2000010];
char a[4000010];
int n;
double f();
int main() {
  cin >> cit;
  int l(strlen(cit));
  for (int i(0); i < l; i++) {
    a[n++] = cit[i];
    if (cit[i + 1] == cit[i] && cit[i] != 'X') a[n++] = 'X';
  }
  double ans;
  if (a[0] == a[n - 1] && a[0] != 'X') {
    a[n++] = 'X';
    ans = f();
    for (int i(n); i > 0; i--) a[i] = a[i - 1];
    a[0] = 'X';
    ans = max(ans, f());
  } else
    ans = f();
  ans *= 100.0;
  ans -= 0.0000005;
  printf("%.6lf", abs(ans));
  return 0;
}
double f() {
  int pasi(0), corect(0), in_plus(0);
  bool prec_modif(0);
  for (int i(0); i < n; i++) {
    char act("LR"[pasi & 1]);
    if (a[i] == act) {
      prec_modif = 0;
      pasi++;
      corect++;
      continue;
    }
    if (a[i] == 'X') {
      pasi++;
      continue;
    }
    in_plus += (prec_modif ? 1 : 0);
    prec_modif = 1 - prec_modif;
    pasi += 2;
    corect++;
  }
  if (pasi & 1) {
    pasi++;
    in_plus += prec_modif;
  }
  if ((1.0 * corect) / (1.0 * pasi) <
      (1.0 * corect - in_plus) / (1.0 * pasi - 2.0 * in_plus)) {
    pasi -= 2 * in_plus, corect -= in_plus;
  }
  return (1.0 * corect) / (1.0 * pasi);
}
