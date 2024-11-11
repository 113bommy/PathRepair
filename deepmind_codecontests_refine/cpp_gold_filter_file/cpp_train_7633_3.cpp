#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int xi[MAX];
int ti[MAX];
int who[MAX];
int res[MAX];
int foo(int i, int j) { return xi[i] < xi[j]; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d%d", ti + i, xi + i);
    who[i] = i;
  }
  int t = 0;
  int a = 0;
  while (a < n) {
    int b = min(n, a + m);
    t = max(t, ti[b - 1]);
    sort(who + a, who + b, foo);
    int x = 0;
    for (int i = a, j; i < b; i = j) {
      for (j = i; j < b && xi[who[i]] == xi[who[j]]; j++)
        ;
      t += xi[who[i]] - x;
      for (int k = (i); k < (int)(j); k++) res[who[k]] = t;
      t += 1 + (j - i) / 2;
      x = xi[who[i]];
    }
    t += x;
    a = b;
  }
  for (int i = 0; i < (int)(n); i++) {
    if (i) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
