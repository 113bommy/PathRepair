#include <bits/stdc++.h>
using namespace std;
int N, len = 1, a[505], b[305];
void add(int num) {
  int i = 1;
  if (num <= 0) {
    while (num <= 0) {
      num += a[i];
      a[i++] = 0;
    }
    while (a[i] == 9) {
      num += a[i];
      a[i++] = 0;
    }
    --num;
    ++a[i];
    if (len < i) len = i;
    i = 1;
  }
  while (num) {
    if (a[i] == 9)
      ++i;
    else
      ++a[i], --num;
  }
  if (len < i) len = i;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", b + i);
  b[0] = 0;
  for (int i = 1; i <= N; ++i) {
    int delta = b[i] - b[i - 1];
    add(delta);
    for (int j = len; j >= 1; --j) printf("%d", a[j]);
    printf("\n");
  }
  return 0;
}
