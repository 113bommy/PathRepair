#include <bits/stdc++.h>
const int maxn = 5e3 + 5;
int n, vis[maxn][maxn], res;
char str[maxn];
inline void read(int &now) {
  char Cget;
  now = 0;
  while (!isdigit(Cget = getchar()))
    ;
  while (isdigit(Cget)) {
    now = now * 10 + Cget - '0';
    Cget = getchar();
  }
}
int main() {
  std::cin >> str;
  n = strlen(str);
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int v = i; v < n; v++) {
      if (str[v] == '(' || str[i] == '?')
        tmp++;
      else
        tmp--;
      if (tmp >= 0)
        vis[i][v]++;
      else
        break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int tmp = 0;
    for (int v = i; v >= 0; v--) {
      if (str[v] == ')' || str[v] == '?')
        tmp++;
      else
        tmp--;
      if (tmp >= 0)
        vis[v][i]++;
      else
        break;
    }
  }
  for (int i = 0; i < n; i++)
    for (int v = 0; v < n; v++)
      if ((i + v) % 2 && vis[i][v] == 2) ++res;
  std::cout << res + 1;
  return 0;
}
