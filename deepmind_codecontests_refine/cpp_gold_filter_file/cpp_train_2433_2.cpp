#include <bits/stdc++.h>
using namespace std;
int n, k, poss[205], a[105], b[105], c[105], d[105];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); i++) scanf("%d", &b[i]);
  for (int i = (1); i <= (n); i++) c[i] = i;
  for (int i = (0); i <= (100); i++) {
    for (int j = (1); j <= (n); j++)
      if (b[j] != c[j]) goto gf;
    poss[i + 100] = true;
  gf:;
    for (int j = (1); j <= (n); j++) d[j] = c[a[j]];
    for (int j = (1); j <= (n); j++) c[j] = d[j];
  }
  for (int i = (1); i <= (n); i++) c[i] = i;
  for (int i = (0); i <= (100); i++) {
    for (int j = (1); j <= (n); j++)
      if (b[j] != c[j]) goto gb;
    poss[100 - i] = true;
  gb:;
    for (int j = (1); j <= (n); j++) d[a[j]] = c[j];
    for (int j = (1); j <= (n); j++) c[j] = d[j];
  }
  if (poss[100]) {
    printf("NO\n");
    return 0;
  }
  int l = -1, r = 201;
  for (int i = (100); i >= (0); i--)
    if (poss[i]) {
      l = i;
      break;
    }
  for (int i = (100); i <= (200); i++)
    if (poss[i]) {
      r = i;
      break;
    }
  int step = 100 - l;
  if (step % 2 == k % 2) {
    if (step == 1 && k > 1 && r == 101) {
    } else if (step > k) {
    } else {
      printf("YES\n");
      return 0;
    }
  }
  step = r - 100;
  if (step % 2 == k % 2) {
    if (step == 1 && k > 1 && l == 99) {
    } else if (step > k) {
    } else {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
