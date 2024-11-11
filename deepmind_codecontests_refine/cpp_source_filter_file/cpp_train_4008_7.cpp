#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  int record[n + 5];
  memset(record, 0, sizeof(record));
  for (int i = 1; i <= (2 * n); i++) {
    scanf("%d", &record[i]);
  }
  sort(record + 1, record + n + 1);
  int min_n = 0, min_2n = 0;
  min_n = record[1], min_2n = record[n + 1];
  double max_possible = (double)(w) / (3.0 * (double)n);
  if (max_possible > min_n) {
    max_possible = min_n;
  }
  if (min_2n < (2.0 * max_possible)) {
    max_possible = (double)min_2n / (2.0);
  }
  max_possible *= 3.0;
  max_possible *= (double)n;
  printf("%f\n", max_possible);
  return 0;
}
