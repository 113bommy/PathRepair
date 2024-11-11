#include <bits/stdc++.h>
char d[1000000];
int s[1000000] = {0};
int main() {
  int i;
  int n;
  scanf("%d", &n);
  scanf("%s", &d);
  for (i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }
  int results = 0;
  for (i = 0; i < n; ++i) {
    if (d[results] == '>') {
      results = results + s[results];
    } else {
      results = results - s[results];
    }
    if ((results >= n) || (results <= 0)) {
      printf("FINITE");
      return 0;
    }
  }
  if ((results >= n) || (results <= 0)) {
    printf("FINITE");
  } else {
    printf("INFINITE");
  }
  return 0;
}
