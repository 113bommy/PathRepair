#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  int n, m[17], r[17], x[1000000], kolvo = 0;
  double result;
  scanf("%d", &n);
  for (int i = 0; i < 1000000; i++) x[i] = 0;
  for (int i = 0; i < n; i++) scanf("%d", &m[i]);
  for (int i = 0; i < n; i++) scanf("%d", &r[i]);
  for (int i = 0; i < 1000000; i++) {
    for (int j = 0; j < n; j++) {
      if (i % m[j] == r[j]) x[i]++;
    }
  }
  for (int i = 0; i < 1000000; i++)
    if (x[i] > 0) kolvo++;
  result = kolvo / 1000000.0;
  printf("%100.4f", (float)result);
  return 0;
}
