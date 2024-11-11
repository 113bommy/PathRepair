#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[10000];
  int n, i, pranto = 0;
  gets(s);
  n = strlen(s);
  sort(s, s + n);
  for (i = 0; i < n; i++) {
    if (s[i] > 96 && s[i] < 123) {
      pranto++;
      if (s[i] == s[i + 1]) pranto--;
    }
  }
  printf("%d\n", pranto);
  pranto = 0;
}
