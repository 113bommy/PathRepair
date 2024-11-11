#include <bits/stdc++.h>
using namespace std;
char ar[300007];
int Q[300007], at, dn[300007];
int maxi = -1, a = 0, b = -1, N;
void kont(int i, int j) {
  int t;
  if (i == 0)
    t = dn[j];
  else
    t = dn[j] - dn[i - 1];
  if (maxi < t) {
    maxi = t;
    a = i;
    b = j;
  }
}
void oku() {
  scanf(" %s", ar);
  N = strlen(ar);
  for (int i = 0; i < N; i++) {
    if (i) dn[i] = dn[i - 1];
    if (ar[i] == '[') dn[i]++;
  }
  Q[0] = -1;
  for (int i = 0; i < N; i++) {
    if (ar[i] == '(' || ar[i] == '[') Q[++at] = i;
    if (ar[i] == ']' || ar[i] == ')') {
      if (at == 0) {
        Q[0] = i;
        continue;
      }
      if (ar[i] == ']') {
        if (ar[Q[at]] == '[') {
          kont(Q[at - 1] + 1, i);
          at--;
        } else {
          Q[0] = i;
          at = 0;
          continue;
        }
      }
      if (ar[i] == ')') {
        if (ar[Q[at]] == '(') {
          kont(Q[at - 1] + 1, i);
          at--;
        } else {
          Q[0] = i;
          at = 0;
          continue;
        }
      }
    }
  }
  if (maxi == -1) maxi = 0;
  printf("%d\n", maxi);
  for (int i = a; i <= b; i++) printf("%c", ar[i]);
  printf("\n");
}
int main() {
  oku();
  return 0;
}
