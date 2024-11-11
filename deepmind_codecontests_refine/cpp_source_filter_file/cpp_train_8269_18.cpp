#include <bits/stdc++.h>
using namespace std;
int lap[100003];
int main() {
  int n, det = 0, a, b, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    lap[a - 1] = b;
  }
  for (i = 0; i < n; i++) {
    if (i > 0 && lap[i] < lap[0]) {
      det = 1;
      break;
    }
  }
  if (det)
    printf("Happy Alex\n");
  else
    printf("Poor Alex\n");
  return 0;
}
