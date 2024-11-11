#include <bits/stdc++.h>
using namespace std;
int N;
int ki[(100005)];
int bi[(100005)];
int A[(100005)];
inline int sgn(int a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
bool cmp(int a, int b) {
  long long aa = -bi[a];
  aa *= ki[b];
  long long bb = -bi[b];
  bb *= ki[a];
  return aa < bb;
}
int main() {
  int i;
  int j = 0;
  scanf("%d", &N);
  for (i = 0; i < N; ++i) {
    int k, b;
    scanf("%d %d", &k, &b);
    if (k < 0) {
      b = -b;
      k = -k;
    }
    if (k != 0) {
      ki[i] = k;
      bi[i] = b;
      A[j++] = i;
    }
  }
  sort(A, A + j, cmp);
  int sol = (j > 0);
  for (i = 1; i < j; ++i) {
    if (cmp(A[i - 1], A[i])) ++sol;
  }
  printf("%d\n", sol);
  return 0;
}
