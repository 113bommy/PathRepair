#include <bits/stdc++.h>
using namespace std;
int n, m;
int wins[3000];
char tourn[3000][3010];
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) tourn[i][j] = 'D';
    tourn[i][m] = '\0';
    tourn[i][i] = 'X';
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", wins + i);
    wins[i] -= m - 1;
    sum += wins[i];
  }
  if (sum < 0) {
    printf("no\n");
    return 0;
  }
  if (m != n) {
    int mn = sum / (m - n);
    int reps = sum % (m - n);
    if (-1 * mn > wins[n - 1]) {
      printf("no\n");
      return 0;
    }
    for (int i = n; i < m - reps; i++) wins[i] = -1 * mn;
    for (int i = m - reps; i < m; i++) wins[i] = -1 * (mn + 1);
  } else if (sum != 0) {
    printf("no\n");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    if (wins[i] > m - i - 1) {
      printf("no\n");
      return 0;
    }
    int end_idx = m - 1;
    int next_idx = m - 1;
    while (wins[i] > 0) {
      while (next_idx >= 0 && wins[next_idx] == wins[end_idx]) next_idx--;
      if (end_idx - next_idx > wins[i]) {
        for (int j = next_idx + 1; j < next_idx + 1 + wins[i]; j++) {
          wins[j]++;
          tourn[i][j] = 'W';
          tourn[j][i] = 'L';
        }
        wins[i] = 0;
      } else {
        for (int j = next_idx + 1; j <= end_idx; j++) {
          wins[j]++;
          tourn[i][j] = 'W';
          tourn[j][i] = 'L';
        }
        wins[i] -= (end_idx - next_idx);
        end_idx = next_idx;
      }
    }
  }
  printf("yes\n");
  for (int i = 0; i < m; i++) {
    printf("%s\n", tourn[i]);
  }
}
