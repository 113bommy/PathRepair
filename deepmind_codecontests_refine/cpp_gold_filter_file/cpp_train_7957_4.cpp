#include <bits/stdc++.h>
const int MAX = 1e3 + 11;
using namespace std;
char A[MAX];
int W[33];
int main() {
  scanf("%s", (A));
  int(K);
  scanf("%d", &K);
  for (int i = 0; i < (26); ++i) scanf("%d", &(W[i]));
  int N = int(strlen(A)), mx = 0;
  for (int i = 0; i < (26); ++i) mx = max(mx, W[i]);
  int r1 = 0, r2 = 0;
  for (int i = 0; i < (N); ++i) r1 += (i + 1) * W[A[i] - 'a'];
  for (int i = 0; i < (K); ++i) r1 += (N + i + 1) * mx;
  for (int i = 0; i < (K); ++i) r2 += (i + 1) * mx;
  for (int i = 0; i < (N); ++i) r2 += (K + i + 1) * W[A[i] - 'a'];
  printf("%d", max(r1, r2));
  return 0;
}
