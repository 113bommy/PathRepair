#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, flag = 0;
  int map[26];
  memset(map, 0, sizeof(map));
  char c;
  scanf("%d%d", &m, &n);
  for (int i = 0; i <= m; i++) {
    scanf("%c", &c);
    int k = c - 'a';
    map[k]++;
    if (map[k] > n) {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    printf("YES\n");
  else
    printf("NO\n");
}
