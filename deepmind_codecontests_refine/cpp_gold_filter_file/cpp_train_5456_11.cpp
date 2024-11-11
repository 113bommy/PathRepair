#include <bits/stdc++.h>
using namespace std;
__inline bool nextInt(int &val) {
  char ch;
  int sgn = 1;
  while ((ch = getchar()) != EOF) {
    if (ch == '-') sgn = -1;
    if (ch >= '0' && ch <= '9') break;
  }
  if (ch == EOF) return false;
  val = (int)(ch - '0');
  while (true) {
    ch = getchar();
    if (ch >= '0' && ch <= '9') {
      val = 10 * val + (int)(ch - '0');
    } else
      break;
  }
  val *= sgn;
  return true;
}
__inline bool nextString(string &s) {
  char ch;
  while ((ch = getchar()) != EOF) {
    if (ch >= 33 && ch <= 126) break;
  }
  if (ch == EOF) return false;
  s = string(1, ch);
  while (true) {
    ch = getchar();
    if (ch >= 33 && ch <= 126) {
      s = s + string(1, ch);
    } else
      break;
  }
  return true;
}
int n;
double a[4888];
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &n);
  double r = 0.0, ret = 1000000.0 * 200000.0;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < (2 * n); i++) {
    scanf("%lf", a + i);
    r += a[i] - (int)a[i];
    if (a[i] - (int)a[i] < 1e-9)
      c0++;
    else
      c1++;
  }
  for (int c = 0; c < (c0 + 1); c++) {
    int x1 = n - c;
    if (x1 >= 0) ret = 1e-9 + min(ret, ((r - x1) > 0 ? (r - x1) : -(r - x1)));
  }
  printf("%.3lf\n", ret);
  return 0;
}
