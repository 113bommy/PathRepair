#include <bits/stdc++.h>
using namespace std;
int lenA, lenB;
int A[1000004];
int B[1000004];
int idxB[1000004];
int lenP = 0, idxP = 0;
long long P[1000004];
int main() {
  scanf("%d %d", &lenA, &lenB);
  for (int i = 0, _n = (lenA); i < _n; ++i) scanf("%d", A + i);
  memset(idxB, -1, sizeof(idxB));
  for (int j = 0, _n = (lenB); j < _n; ++j) {
    scanf("%d", B + j);
    idxB[B[j]] = j;
  }
  long long offset = 0;
  int res = 0;
  for (int k = 0, _n = (lenA * 2); k < _n; ++k) {
    long long p = idxB[A[k % lenA]];
    if (p < 0) {
      idxP = lenP = 0;
      continue;
    }
    p += offset;
    if (lenP > 0 && P[lenP - 1] >= p) {
      p += lenB;
      offset += lenB;
    }
    P[lenP++] = p;
    while (P[idxP] <= p - lenB) ++idxP;
    int len = lenP - idxP;
    res = max(res, len);
  }
  printf("%d\n", res);
  return 0;
}
