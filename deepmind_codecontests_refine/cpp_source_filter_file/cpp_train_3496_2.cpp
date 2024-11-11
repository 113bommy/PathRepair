#include <bits/stdc++.h>
using namespace std;
int ans, k;
int main() {
  string s, s3 = "", s4 = "";
  cin >> s;
  scanf("%d", &k);
  int c = 0, bo = 0;
  for (int i = s.size() - 1; i > -1; i--) {
    if (!bo) {
      if (s[i] != '0')
        c++;
      else {
        k--;
        s3 += s[i];
      }
      if (!k) bo = 1;
    } else
      s3 += s[i];
  }
  int df = s3.size() - 1;
  while (1) {
    if (df < 0 || s3[df] != '0')
      break;
    else
      df--;
  }
  if (df < 0) df++;
  if (!df)
    c += (s3.size() - 1);
  else
    c += (s3.size() - df);
  printf("%d\n", c);
}
