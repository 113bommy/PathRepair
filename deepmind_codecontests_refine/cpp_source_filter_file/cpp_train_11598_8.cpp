#include <bits/stdc++.h>
using namespace std;
char str[20];
int len;
int DFS(int sta) {
  if (sta == len) return 1;
  if (str[sta] != '1') return 0;
  if (DFS(sta + 1)) return 1;
  if (sta + 1 >= len && str[sta + 1] != '4') return 0;
  if (DFS(sta + 2)) return 1;
  if (sta + 2 >= len || str[sta + 2] != '4') return 0;
  if (DFS(sta + 3)) return 1;
  return 0;
}
int main() {
  while (scanf("%s", &str) != EOF) {
    len = strlen(str);
    if (DFS(0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
