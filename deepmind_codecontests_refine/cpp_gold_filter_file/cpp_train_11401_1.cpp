#include <bits/stdc++.h>
using namespace std;
char str[100100];
int main() {
  int n;
  int mxL = 1;
  int crtL = 1;
  int cntO2 = 0;
  int cntBlock = 1;
  int mxD = 0;
  bool lst;
  scanf("%d%s", &n, str);
  for (int i = 0; i < n; i++) str[i] = str[i] == '1';
  lst = str[0];
  for (int i = 1; i < n; i++) {
    if (str[i] == lst)
      mxL = max(mxL, ++crtL);
    else {
      cntBlock++;
      lst = str[i];
      cntO2 += (crtL >= 2);
      crtL = 1;
    }
  }
  mxL = max(mxL, crtL);
  cntO2 += (crtL >= 2);
  if (cntO2 > 1 || mxL > 2)
    cntBlock += 2;
  else if (mxL > 1)
    cntBlock++;
  printf("%d\n", cntBlock);
}
