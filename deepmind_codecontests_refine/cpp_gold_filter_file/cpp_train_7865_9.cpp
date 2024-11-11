#include <bits/stdc++.h>
using namespace std;
int P[10000000 / 3] = {2, 3}, p = 2;
bool I[10000000], C[10000000];
void Criba() {
  for (int i = 5; p <= 100002; i += (i % 6 == 1) ? 4 : 2)
    if (!I[i]) {
      if (i < 10000)
        for (int j = i * i; j < 10000000; j += i + i) I[j] = 1;
      P[p++] = i;
    }
}
int n, k, x;
int main() {
  Criba();
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x < 10000000) C[x] = 1;
  }
  if (k == 2) {
    printf("0\n");
    return 0;
  }
  if (C[1]) {
    printf("1\n");
    return 0;
  }
  if (k > P[100002]) {
    printf("-1\n");
    return 0;
  }
  bool is = 1;
  int i = 0;
  for (; is && P[i] < k; i++) is = C[P[i]];
  if (is)
    printf("%d\n", i);
  else
    printf("-1\n");
  return 0;
}
