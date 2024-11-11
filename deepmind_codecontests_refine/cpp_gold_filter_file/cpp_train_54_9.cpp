#include <bits/stdc++.h>
using namespace std;
char s[23];
double r[100003];
struct cmp {
  bool operator()(const double& x, const double& y) const {
    return x - y < -1e-10;
  }
};
map<double, int, cmp> mpx, mpy;
int main() {
  int X, Y, w;
  bool swp = 0;
  scanf("%d%d%d", &X, &Y, &w);
  if (X > Y) swap(X, Y), swp = 1;
  for (int i = 1; i <= Y; i++) {
    sprintf(s, "%d", i);
    int len = strlen(s);
    reverse(s, s + len);
    int j;
    sscanf(s, "%d", &j);
    r[i] = double(i) / j;
  }
  for (int k = 1; k <= Y; k++) mpy[r[k]]++;
  mpx[r[1]]++;
  long long ANS = 100000000000000000ll;
  int ANSx, ANSy, res = mpy[1 / r[1]];
  for (int i = 1, j = Y; i <= X && j >= 1;) {
    if (res >= w) {
      if ((long long)i * j < ANS) {
        ANS = (long long)i * j;
        ANSx = i;
        ANSy = j;
      }
      res -= mpx[1 / r[j]];
      mpy[r[j]]--;
      j--;
    } else {
      i++;
      res += mpy[1 / r[i]];
      mpx[r[i]]++;
    }
  }
  if (swp) swap(ANSx, ANSy);
  if (ANS == 100000000000000000ll)
    printf("-1\n");
  else
    printf("%d %d\n", ANSx, ANSy);
  return 0;
}
