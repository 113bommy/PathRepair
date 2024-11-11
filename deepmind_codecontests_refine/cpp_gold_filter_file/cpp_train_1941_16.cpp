#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int N, Q;
int p[100500];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
  int inv = 0;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      if (p[i] > p[j]) inv++;
    }
  inv %= 2;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((b - a + 1) % 4 == 2) inv = inv ^ 1;
    if ((b - a + 1) % 4 == 3) inv = inv ^ 1;
    if (inv % 2 == 0)
      printf("even\n");
    else
      printf("odd\n");
  }
}
