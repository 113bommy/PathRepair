#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  char m[n][n];
  for (int i = 0; i < n; i++) scanf("%s", &m[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i > 0 && i < n - 1 && j > 0 && j < n - 1)
        if (m[i][j] == 'X')
          if (m[i - 1][j - 1] == 'X' && m[i + 1][j + 1] == 'X' &&
              m[i - 1][j + 1] == 'X' && m[i + 1][j - 1] == 'X')
            cnt++;
  printf("%d\n", cnt);
}
