#include <bits/stdc++.h>
using namespace std;
long long point(long long a, long long b) {
  long long x = 500;
  while (x < 3000 and 2 * a <= b) {
    a *= 2;
    x += 500;
  }
  return x;
}
int main() {
  long long n, i, j, k;
  scanf("%lld", &n);
  long long arr[n + 1][5], count[5], score[5];
  memset(count, 0, sizeof count);
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 5; j++) {
      scanf("%lld", &arr[i][j]);
      if (arr[i][j] == -1) {
        arr[i][j] = 250;
      } else {
        count[j]++;
      }
    }
  }
  for (i = 0; i <= 31 * n; i++) {
    double score_v = 0, score_p = 0;
    for (j = 0; j < 5; j++) {
      bool solved_v = 0, solved_p = 0;
      if (arr[1][j] != 250) solved_v = 1;
      if (arr[2][j] != 250) solved_p = 1;
      long long a = count[j], b = n + i, v = arr[1][j], p = arr[2][j];
      if (solved_v and solved_p and p < v) {
        a += i;
      }
      score[j] = point(a, b);
      score_v += (double)score[j] * (1 - (double)v / 250);
      score_p += (double)score[j] * (1 - (double)p / 250);
    }
    if (score_v > score_p) {
      printf("%lld\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
