#include <bits/stdc++.h>
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  char in[110], cval = 'a';
  char vcw, vccw;
  int out = 0;
  scanf("%s", &in);
  for (int i = 0; i < strlen(in); i++) {
    vcw = cval - in[i];
    if (vcw < 0) vcw += 26;
    vccw = in[i] - cval;
    if (vccw < 0) vccw += 26;
    out += min(vcw, vccw);
    cval = in[i];
  }
  printf("%d", out);
}
