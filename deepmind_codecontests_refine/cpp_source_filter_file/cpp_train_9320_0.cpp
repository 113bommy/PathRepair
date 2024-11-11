#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 10;
int T, n;
int id[N], cnt[10], ans[10];
char s[N];
inline int check(int id) {
  int mini = inf;
  for (int i = 1; i <= 4; i++) mini = min(mini, cnt[i]);
  if (cnt[id] == mini) return 1;
  return 0;
}
inline void cal(char *s, int flag) {
  memset(cnt, 0, sizeof(cnt));
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    if (s[i] == 'G') cnt[1]++;
    if (s[i] == 'H') cnt[2]++;
    if (s[i] == 'R') cnt[3]++;
    if (s[i] == 'S') cnt[4]++;
    if (s[i] == '?' && flag == 0) {
      int t;
      while (1) {
        int t = rand() % 4 + 1;
        if (check(t)) {
          cnt[t]++;
          break;
        }
      }
    }
  }
  int mini = inf;
  for (int i = 1; i <= 4; i++) mini = min(mini, cnt[i]);
  for (int i = 1; i <= 4; i++)
    if (cnt[i] == mini) ans[i] = 1;
}
int main() {
  srand(unsigned(time(0)));
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= 4; i++) id[i] = i;
  for (int i = 1; i <= 200; i++) cal(s, 0);
  if (ans[1]) puts("Gryffindor");
  if (ans[2]) puts("Hufflepuff");
  if (ans[3]) puts("Ravenclaw");
  if (ans[4]) puts("Slytherin");
  memset(ans, 0, sizeof(ans));
  return 0;
}
