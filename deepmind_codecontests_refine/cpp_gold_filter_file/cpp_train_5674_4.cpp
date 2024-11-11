#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = -1;
  scanf("%i %i", &n, &m);
  int counts[n], arr[n];
  memset(counts, 0, sizeof(counts));
  for (int i = 0; i < m; i++) {
    int x = -1, i1 = -1;
    for (int j = 0; j < n; j++) {
      scanf("%i", &arr[j]);
      if (arr[j] > x) {
        x = arr[j];
        i1 = j;
      }
    }
    counts[i1]++;
  }
  int x = -1, i1 = -1;
  for (int i = 0; i < n; i++) {
    if (counts[i] > x) {
      x = counts[i];
      i1 = i;
    }
  }
  printf("%i\n", i1 + 1);
  return 0;
}
