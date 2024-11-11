#include <bits/stdc++.h>
using namespace std;
char a[100002], s[100002];
int n;
int main() {
  int i, k;
  scanf("%s", a);
  n = strlen(a);
  k = -1;
  s[++k] = a[n - 1];
  for (i = n - 2; i >= 0; i--) {
    if (a[i] >= s[k]) {
      s[++k] = a[i];
    }
  }
  for (i = k; i >= 0; i--) printf("%c", s[i]);
  printf("\n");
  return 0;
}
