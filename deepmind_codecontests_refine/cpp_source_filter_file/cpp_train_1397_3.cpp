#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int storage[200001];
int storage2[200001];
int* value = storage + 100000;
int* prevalue = storage2 + 100000;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int gtzero = 0, lezero = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]), b[i] *= k;
  for (int i = 0; i < n; i++) {
    b[i] = a[i] - b[i];
    if (b[i] > 0)
      gtzero += b[i];
    else
      lezero += b[i];
  }
  memset(storage, 1, sizeof(storage));
  memset(storage2, 1, sizeof(storage2));
  value[0] = prevalue[0] = 0;
  for (int i = 0; i < n; i++) {
    int C = b[i];
    for (int j = -10000; j <= 10000; j++) {
      value[j] = max(prevalue[j], prevalue[j - b[i]] + a[i]);
    }
    memcpy(storage2, storage, sizeof(storage));
  }
  if (value[0] > 0)
    printf("%d\n", value[0]);
  else
    printf("-1\n");
  return 0;
}
