#include <bits/stdc++.h>
using namespace std;
const int MX = (int)2e5 + 5;
int N, M, a[MX], p;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      if (a[j] < a[i]) p ^= 1;
    }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    if ((r - l + 1) / 2 == 1) p ^= 1;
    if (p)
      printf("odd\n");
    else
      printf("even\n");
  }
  return 0;
}
