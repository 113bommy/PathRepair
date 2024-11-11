#include <bits/stdc++.h>
using namespace std;
inline int gn(char x) { return x - '0'; }
int main() {
  int ans = 1;
  char s[10];
  scanf("%s", s);
  int n = strlen(s);
  int cnt[10];
  cnt[0] = 2;
  cnt[1] = 7;
  cnt[2] = 2;
  cnt[3] = 3;
  cnt[4] = 4;
  cnt[5] = 4;
  cnt[6] = 2;
  cnt[7] = 5;
  cnt[8] = 1;
  cnt[9] = 2;
  for (int i = 0; i < n; i++) {
    ans *= cnt[gn(s[i])];
  }
  printf("%d", ans);
  return 0;
}
