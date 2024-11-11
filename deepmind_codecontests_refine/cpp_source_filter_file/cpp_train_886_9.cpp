#include <bits/stdc++.h>
long m[5002][5002] = {};
int main() {
  int a;
  long md1[5002] = {};
  scanf("%d", &a);
  for (int i = 0; i < a; i++) scanf("%ld", &m[0][i]);
  for (int i = 1; i < a; i++) {
    long md[5002] = {};
    for (int j = 0; j < i; j++) md[m[0][j]]++;
    for (int j = i; j < a; j++) {
      md[m[0][j]]++;
      if (md[m[i - 1][j - 1]] < md[m[0][j]])
        m[i][j] = m[0][j];
      else if (md[m[i - 1][j - 1]] > md[m[0][j]])
        m[i][j] = m[i - 1][j - 1];
      else if (m[i - 1][j - 1] < m[0][j])
        m[i][j] = m[i - 1][j - 1];
      else
        m[i][j] = m[0][j];
      md[m[0][j - i]]--;
    }
  }
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++) md1[m[i][j]]++;
  for (int i = 1; i <= a; i++) printf("%ld", md1[i]);
}
