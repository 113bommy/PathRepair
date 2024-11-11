#include <bits/stdc++.h>
using namespace std;
int cnt[6];
char s[100];
bool cmp(int a, int b) { return a > b; }
int ch() {
  int cn = 0;
  sort(cnt, cnt + 6, cmp);
  if (cnt[1] == 0) return 1;
  if (cnt[2] == 0) {
    if (cnt[0] == 5) return 1;
    return 2;
  }
  if (cnt[3] == 0) {
    if (cnt[0] == 4) return 2;
    if (cnt[0] == 3) return 3;
    return 2;
  }
  if (cnt[4] == 0) {
    if (cnt[0] == 3) return 4;
    if (cnt[0] == 2) return 5;
  }
  if (cnt[5] == 0) return 18;
  return 30;
}
int main() {
  while (~scanf("%s", s)) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 6; i++) {
      if (s[i] == 'R')
        cnt[0]++;
      else if (s[i] == 'O')
        cnt[1]++;
      else if (s[i] == 'Y')
        cnt[2]++;
      else if (s[i] == 'G')
        cnt[3]++;
      else if (s[i] == 'B')
        cnt[4]++;
      else
        cnt[5]++;
    }
    int ans = ch();
    printf("%d\n", ans);
  }
}
