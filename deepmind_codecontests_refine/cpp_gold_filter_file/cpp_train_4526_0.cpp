#include <bits/stdc++.h>
using namespace std;
int lngth, lst, open, close, rest_open, rest_close, times;
char s[100001];
int main() {
  while (scanf("%s\n", s) != EOF) {
    lngth = strlen(s);
    open = 0;
    close = 0;
    rest_open = 0;
    rest_close = 0;
    times = 0;
    for (int i = 0; i < lngth; ++i)
      if (s[i] == '#') lst = i;
    for (int i = lngth - 1; i > lst; --i) {
      if (s[i] == '(') {
        ++rest_open;
        if (rest_open > rest_close) {
          printf("-1\n");
          return 0;
        }
      } else
        ++rest_close;
    }
    for (int i = 0; i < lst; ++i) {
      if (s[i] == '(')
        ++open;
      else if (s[i] == ')')
        ++close;
      else {
        ++times;
        ++close;
      }
      if (open < close) {
        printf("-1\n");
        return 0;
      }
    }
    if (open + rest_open <= close + rest_close)
      printf("-1\n");
    else {
      for (int i = 0; i < times; ++i) printf("1\n");
      printf("%d\n", open + rest_open - close - rest_close);
    }
  }
  return 0;
}
