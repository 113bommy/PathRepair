#include <bits/stdc++.h>
using namespace std;
int n, ans[2] = {2000000, 0};
char s[202020], arr[7][3] = {{'R', 'G', 'B'}, {'R', 'B', 'G'}, {'G', 'R', 'B'},
                             {'G', 'B', 'R'}, {'B', 'R', 'G'}, {'B', 'G', 'R'}};
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int j = 1; j <= 6; j++) {
    int re = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] != arr[j][i % 3]) re++;
    }
    if (re < ans[0]) {
      ans[0] = re;
      ans[1] = j;
    }
  }
  printf("%d\n", ans[0]);
  for (int i = 1; i <= n; i++) printf("%c", arr[ans[1]][i % 3]);
}
