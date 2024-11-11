#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int nd, md, tmp, nmxd = -1, nn, sn, mmxd = -1, mm, sm;
bool sign() {
  bool flag = (nn < 0 || mm < 0);
  if (nn < 0 && mm < 0) flag = 0;
  return flag;
}
void simp() {
  for (int i = 100; i > 0; i--) {
    if (nn % i == 0 && mm % i == 0) {
      sn = nn / i;
      sm = mm / i;
      return;
    }
  }
}
int main() {
  cin >> nd >> md;
  for (int i = 0; i <= nd; i++) {
    cin >> tmp;
    if (tmp && nmxd == -1) {
      nmxd = nd - i;
      nn = tmp;
    }
  }
  for (int i = 0; i <= md; i++) {
    cin >> tmp;
    if (tmp && mmxd == -1) {
      mmxd = md - i;
      mm = tmp;
    }
  }
  if (nmxd == mmxd) {
    if (sign()) printf("-");
    simp();
    printf("%d/%d\n", abs(sn), abs(sm));
  } else if (nmxd > mmxd) {
    if (sign()) printf("-");
    printf("Infinity\n");
  } else if (nmxd < mmxd)
    printf("0/1\n");
  return 0;
}
