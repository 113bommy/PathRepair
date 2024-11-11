#include <bits/stdc++.h>
using namespace std;
char s[2000005], res[2000005];
int main() {
  long long na, kon;
  scanf("%s", s);
  kon = -1;
  for (int i = 1; s[i]; i++) {
    if (kon == -1 || s[i] != res[kon]) {
      res[++kon] = s[i];
    } else
      kon--;
  }
  res[kon + 1] = 0;
  printf("%s", res);
}
