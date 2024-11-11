#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, vis[10] = {0}, v = 0;
  char s[20], name[10][20] = {"vaporeon", "jolteon", "flareon", "espeon",
                              "umbreon",  "leafeon", "glaceon", "sylveon"};
  scanf("%d%s", &m, &s);
  for (i = 0; i < 8; i++) {
    if (strlen(name[i]) == m) {
      vis[i]++;
    }
  }
  for (i = 0; s[i] != 0; i++) {
    for (j = 0; j < 8; j++) {
      if (isalpha(s[i]) && vis[j] != 0 && s[i] == name[j][i]) {
        vis[j]++;
        v = max(vis[j], v);
      }
    }
  }
  for (i = 0; i < 8; i++) {
    if (vis[i] == v) break;
  }
  puts(name[i]);
}
