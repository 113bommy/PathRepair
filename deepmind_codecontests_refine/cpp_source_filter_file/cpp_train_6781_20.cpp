#include <bits/stdc++.h>
using namespace std;
const int X = 100010;
vector<int> e[X], s[X];
void make() {
  for (int i = 2; i < X; i++)
    for (int j = i; j < X; j += i) s[j].push_back(i);
}
int main() {
  make();
  int n, x, y, i, j, cnt;
  scanf("%d", &n);
  for (i = 0; i < X; i++) e[i].push_back(0);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    cnt = (bool)y;
    for (j = 0; j < s[x].size(); j++)
      if (e[s[x][j]].back() < i - y) cnt++;
    for (j = 0; j < s[x].size(); j++) e[s[x][j]].push_back(i);
    printf("%d\n", cnt);
  }
  return 0;
}
