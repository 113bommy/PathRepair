#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  const int m = 2e5;
  vector<int> cnt(m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x - 1];
  }
  int ans = 0;
  int best_i = -1, best_j = -1;
  for (int i = 0, j = 0;;) {
    while (i < m && cnt[i] < 1) ++i;
    if (i == m) break;
    int sum = cnt[i];
    j = i + 1;
    while (j < m && cnt[j] >= 2) {
      sum += cnt[j];
      ++j;
    }
    if (j != m && cnt[j] == 1) {
      sum += cnt[j];
      ++j;
    }
    if (ans < sum) {
      ans = sum;
      best_i = i;
      best_j = j;
    }
    if (i != j - 1 && cnt[j - 1] == 1) {
      i = j - 1;
    } else {
      i = j;
    }
  }
  printf("%d\n", ans);
  for (int i = best_i; i < best_j; ++i) {
    int times = (cnt[i] + 1) / 2;
    for (int j = 0; j < times; ++j) {
      printf("%d ", i + 1);
    }
  }
  for (int i = best_j - 1; i >= best_i; --i) {
    int times = cnt[i] / 2;
    for (int j = 0; j < times; ++j) {
      printf("%d ", i + 1);
    }
  }
  putchar('\n');
}
