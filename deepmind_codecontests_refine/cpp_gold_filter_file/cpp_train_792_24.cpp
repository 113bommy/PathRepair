#include <bits/stdc++.h>
using namespace std;
int n, m;
char T[110][110];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (n); ++i) scanf("%s", &T[i]);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      int c = 0;
      for (int k = (0); k < (m); ++k)
        if (T[i][j] == T[i][k]) ++c;
      for (int k = (0); k < (n); ++k)
        if (T[i][j] == T[k][j]) ++c;
      if (c == 2) printf("%c", T[i][j]);
    }
  printf("\n");
  return 0;
}
