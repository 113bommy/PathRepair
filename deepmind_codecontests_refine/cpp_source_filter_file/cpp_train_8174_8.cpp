#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[101010], b[101010], r[101010], l[101010];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    r[i] = a[i] - b[i];
  }
  for (int i = 0; i < n; i++) {
    l[i] = a[i] - b[(i + n - 1) % n];
  }
  bool can[101010];
  memset(can, false, sizeof(can));
  int min = 1;
  for (int i = 0; i < n; i++) {
    if (i > 0) r[i] += r[i - 1];
    if (min > r[i]) min = r[i];
  }
  for (int i = 0; i < n; i++) {
    if (min == r[i]) can[(i + 1) % n] = true;
  }
  min = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (l[i] < n - 1) l[i] += l[i + 1];
    if (min > l[i]) min = l[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (min == l[i]) can[(i + n - 1) % n] = true;
  }
  int num = 0;
  for (int i = 0; i < n; i++) {
    if (can[i]) num++;
  }
  printf("%d\n", num);
  for (int i = 0; i < n; i++) {
    if (can[i]) printf("%d ", i + 1);
  }
  printf("\n");
  return 0;
}
