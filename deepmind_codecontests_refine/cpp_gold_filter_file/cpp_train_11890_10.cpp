#include <bits/stdc++.h>
using namespace std;
int flag[205][205];
int ask(int i, int j) {
  if (i == j) return 0;
  if (flag[i][j]) return flag[i][j];
  printf("? %d %d\n", i, j);
  fflush(stdout);
  char s[2];
  scanf("%s", s);
  if (s[0] == '<') {
    flag[i][j] = -1;
    flag[j][i] = 1;
    return -1;
  } else {
    flag[i][j] = 1;
    flag[j][i] = -1;
    return 1;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    memset(flag, 0, sizeof(flag));
    vector<int> groups[2];
    for (int i = 1; i < n; i++) groups[0].push_back(i);
    groups[1].push_back(n);
    groups[1].push_back(n + 1);
    for (int i = n + 2; i <= 2 * n + 1; i++) {
      auto min1 = groups[0].begin(), min2 = groups[1].begin();
      for (auto j = groups[0].begin() + 1; j != groups[0].end(); j++)
        if (ask(*min1, *j) > 0) min1 = j;
      for (auto j = groups[1].begin() + 1; j != groups[1].end(); j++)
        if (ask(*min2, *j) > 0) min2 = j;
      if (ask(*min1, *min2) < 0) {
        groups[0].erase(min1);
        groups[0].push_back(i);
      } else {
        groups[1].erase(min2);
        groups[1].push_back(i);
      }
    }
    printf("!\n");
    fflush(stdout);
  }
}
