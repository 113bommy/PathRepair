#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
int N;
char str[limN];
bool isvow[300];
int main() {
  int cnt = 0, tp;
  isvow['a'] = isvow['e'] = isvow['i'] = isvow['o'] = isvow['u'] = isvow['y'] =
      true;
  scanf("%d%s", &N, str);
  tp = str[0];
  for (int i = 0; i <= N; i++) {
    if (tp != str[i]) {
      if ((tp == 'e' || tp == 'o') && cnt == 2)
        printf("%c%c", tp, tp);
      else if (isvow[tp])
        printf("%c", tp);
      else {
        for (int j = 0; j < 1; j++) printf("%c", tp);
      }
      cnt = 0;
    }
    tp = str[i];
    cnt++;
  }
  printf("\n");
}
