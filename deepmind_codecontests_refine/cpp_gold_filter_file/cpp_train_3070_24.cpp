#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char s[100001], t[100001];
int n;
int main() {
  scanf("%s %s", s, t);
  n = strlen(s);
  int dif = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      dif++;
    }
  }
  if (dif & 1) {
    printf("impossible");
  } else {
    int a = dif >> 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) {
        printf("%c", s[i]);
      } else {
        if (a) {
          printf("%c", s[i]);
          a--;
        } else {
          printf("%c", t[i]);
        }
      }
    }
  }
  puts("");
  return 0;
}
