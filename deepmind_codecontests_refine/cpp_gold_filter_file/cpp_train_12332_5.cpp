#include <bits/stdc++.h>
using namespace std;
int shirts[6], print[1000];
char human[60];
int pd(int x) {
  int lxl = 0;
  for (int i = x; i <= 5; i++) {
    if (shirts[i]) {
      lxl = i;
      break;
    } else {
      if (((2 * x - i) > 0) && (2 * x - i < 6) && (shirts[2 * x - i])) {
        lxl = 2 * x - i;
        break;
      }
    }
  }
  if (!lxl) {
    for (int i = x - 1; i > 0; i--) {
      if (shirts[i]) {
        lxl = i;
        break;
      }
    }
  }
  return lxl;
}
int main() {
  int k;
  for (int i = 1; i <= 5; i++) scanf("%d", &shirts[i]);
  scanf("%d", &k);
  for (int j = 1; j <= k; j++) {
    scanf("%s", human);
    int zz = strlen(human), yy = 0;
    if (zz == 2) yy = pd(4);
    if (zz == 3) yy = pd(5);
    if (human[0] == 'S') yy = pd(1);
    if (human[0] == 'M') yy = pd(2);
    if (human[0] == 'L') yy = pd(3);
    print[j] = yy;
    shirts[yy]--;
  }
  for (int i = 1; i <= k; i++) {
    if (print[i] == 1) cout << "S" << endl;
    if (print[i] == 2) cout << "M" << endl;
    if (print[i] == 3) cout << "L" << endl;
    if (print[i] == 4) cout << "XL" << endl;
    if (print[i] == 5) cout << "XXL" << endl;
  }
  return 0;
}
