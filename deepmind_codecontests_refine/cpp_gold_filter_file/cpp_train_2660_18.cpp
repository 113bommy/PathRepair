#include <bits/stdc++.h>
int main() {
  int m[5];
  scanf("%d%d%d%d", &m[1], &m[2], &m[3], &m[4]);
  int t = 0, s = 0;
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++)
      if (i != j)
        for (int k = 1; k <= 4; k++)
          if (i != k && j != k) {
            if (m[i] < m[k] + m[j] && m[j] < m[k] + m[i] && m[k] < m[i] + m[j])
              t = 1;
            if (m[i] == m[k] + m[j] || m[j] == m[k] + m[i] ||
                m[k] == m[i] + m[j])
              s = 1;
          }
  if (t)
    printf("TRIANGLE\n");
  else if (s)
    printf("SEGMENT\n");
  else
    printf("IMPOSSIBLE\n");
}
