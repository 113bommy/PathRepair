#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int least = 9999999;
  int numbers[55];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &numbers[i]);
  }
  sort(numbers, numbers + m);
  for (int i = 0; i <= m - n; i++) {
    least = min(least, numbers[i + n - 1] - numbers[i]);
  }
  printf("%d\n", least);
  return 0;
}
