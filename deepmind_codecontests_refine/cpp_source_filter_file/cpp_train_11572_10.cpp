#include <bits/stdc++.h>
int n;
char l[150001];
char r[150001];
int ml[30][150000];
int ml_cnt[30];
int mr[30][150000];
int mr_cnt[30];
int result[75000][2];
int result_cnt;
int main() {
  scanf("%d", &n);
  scanf("%s %s", l, r);
  for (int i = 0; i < n; i++) {
    if (l[i] == '?') {
      ml[29][ml_cnt[29]++] = i + 1;
    } else {
      ml[l[i] - 'a'][ml_cnt[l[i] - 'a']++] = i + 1;
    }
    if (r[i] == '?') {
      mr[29][mr_cnt[29]++] = i + 1;
    } else {
      mr[r[i] - 'a'][mr_cnt[r[i] - 'a']++] = i + 1;
    }
  }
  for (int i = 0; i < 29; i++) {
    int min = (ml_cnt[i] > mr_cnt[i]) ? mr_cnt[i] : ml_cnt[i];
    for (int j = 0; j < min; j++) {
      result[result_cnt][0] = ml[i][ml_cnt[i]-- - 1];
      result[result_cnt++][1] = mr[i][mr_cnt[i]-- - 1];
    }
  }
  for (int i = 0; i < 30; i++) {
    while (mr_cnt[i] != 0 && ml_cnt[29] != 0) {
      result[result_cnt][0] = ml[29][ml_cnt[29]-- - 1];
      result[result_cnt++][1] = mr[i][mr_cnt[i]-- - 1];
    }
  }
  for (int i = 0; i < 30; i++) {
    while (ml_cnt[i] != 0 && mr_cnt[29] != 0) {
      result[result_cnt][0] = ml[i][ml_cnt[i]-- - 1];
      result[result_cnt++][1] = mr[29][mr_cnt[29]-- - 1];
    }
  }
  printf("%d\n", result_cnt);
  for (int i = 0; i < result_cnt; i++) {
    printf("%d %d\n", result[i][0], result[i][1]);
  }
  return 0;
}
