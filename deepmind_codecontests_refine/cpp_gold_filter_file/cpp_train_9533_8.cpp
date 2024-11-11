#include <bits/stdc++.h>
using namespace std;
string s[1000009];
char c[1000009];
vector<int> lev[1000009];
int i = 0;
int ans = 0;
bool goDeeper(int level, int num) {
  ans = max(ans, level);
  for (int j = 0; j < num; j++) {
    scanf("%[^,|\n],", c);
    s[i] = c;
    lev[level].push_back(i);
    i++;
    int n;
    scanf("%d", &n);
    char x = getchar();
    if (x == '\n') return true;
    if (n) {
      if (goDeeper(level + 1, n)) return true;
    }
  }
  return false;
}
int main() {
  while (1) {
    scanf("%[^(,|\n)]", c);
    s[i] = c;
    lev[0].push_back(i);
    i++;
    int n;
    getchar();
    scanf("%d", &n);
    char x = getchar();
    if (x == '\n') break;
    if (n) {
      if (goDeeper(1, n)) break;
    }
  }
  printf("%d\n", ans + 1);
  for (int i = 0; i <= ans; i++) {
    for (int x : lev[i]) printf("%s ", s[x].c_str());
    puts("");
  }
}
