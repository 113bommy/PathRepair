#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
char s[N][N];
char S[N][N];
int Ans[N][N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (0); i < (2 * n - 1); ++i) scanf("%s", s[i]);
  if (k == 1) {
    int tot = 0, no = 0;
    for (int i = (0); i < (2 * n - 1); ++i)
      for (int j = (0); j < (m - (i % 2 == 0)); ++j)
        tot++, no += (s[i][j] == 'N');
    if (no * 4 > tot)
      puts("NO");
    else {
      puts("YES");
      for (int i = (0); i < (n); ++i)
        for (int j = (0); j < (m); ++j) printf("1%c", j == m - 1 ? '\n' : ' ');
    }
    return 0;
  }
  puts("YES");
  int flag = 0;
  if (n > m) {
    flag = 1;
    for (int i = (0); i < (2 * m - 1); ++i) {
      if (i & 1)
        for (int j = (0); j < (n); ++j) S[i][j] = s[j * 2][i / 2];
      else
        for (int j = (0); j < (n - 1); ++j) S[i][j] = s[j * 2 + 1][i / 2];
    }
    swap(n, m);
  } else {
    for (int i = (0); i < (2 * n - 1); ++i) {
      if (i & 1)
        for (int j = (0); j < (m); ++j) S[i][j] = s[i][j];
      else
        for (int j = (0); j < (m - 1); ++j) S[i][j] = s[i][j];
    }
  }
  for (int i = (0); i < (n); ++i) {
    Ans[i][0] = 1;
    for (int j = (1); j < (m); ++j) {
      if (S[i * 2][j - 1] == 'E')
        Ans[i][j] = Ans[i][j - 1];
      else
        Ans[i][j] = 3 - Ans[i][j - 1];
    }
    if (i) {
      int cc = 0;
      for (int j = (0); j < (m); ++j) {
        if (Ans[i][j] == Ans[i - 1][j] && S[i * 2 - 1][j] == 'N') cc++;
        if (Ans[i][j] != Ans[i - 1][j] && S[i * 2 - 1][j] == 'E') cc++;
      }
      if (cc * 2 >= m)
        for (int j = (0); j < (m); ++j) Ans[i][j] = 3 - Ans[i][j];
    }
  }
  if (!flag)
    for (int i = (0); i < (n); ++i)
      for (int j = (0); j < (m); ++j)
        printf("%d%c", Ans[i][j], j == m - 1 ? '\n' : ' ');
  else
    for (int j = (0); j < (m); ++j)
      for (int i = (0); i < (n); ++i)
        printf("%d%c", Ans[i][j], i == n - 1 ? '\n' : ' ');
  return 0;
}
