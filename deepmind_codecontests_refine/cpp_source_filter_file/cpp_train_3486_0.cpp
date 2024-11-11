#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  cin.ignore();
  char in[n + 5][m + 5];
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%c", &in[i][j]);
    }
    cin.ignore();
  }
  int letter[30];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      memset(letter, 0, sizeof(letter));
      letter[in[i][j] - 'a'] += 1;
      letter[in[i][j + 1] - 'a'] += 1;
      letter[in[i + 1][j] - 'a'] += 1;
      letter[in[i + 1][j + 1] - 'a'] += 1;
      if (letter[0] == 1 && letter[2] == 1 && letter[4] == 1 &&
          letter[5] == 1) {
        ans += 1;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
