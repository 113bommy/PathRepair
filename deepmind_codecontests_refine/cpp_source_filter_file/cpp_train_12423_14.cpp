#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100007];
  scanf("%s\n", &a);
  int n = strlen(a);
  char s[100007];
  scanf("%s\n", &s);
  int m = strlen(s);
  sort(s, s + n);
  int a_i = 0;
  int s_i = n - 1;
  while (a_i < n && s_i >= 0) {
    if (a[a_i] > s[s_i]) {
      a[a_i] = s[s_i];
      --s_i;
    }
    ++a_i;
  }
  printf("%s\n", a);
  return 0;
}
