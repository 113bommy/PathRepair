#include <bits/stdc++.h>
const int MAX = 1e5 + 11;
using namespace std;
int N, M, a, b;
int A[MAX], B[MAX];
int main() {
  scanf("%d %d", &N, &M);
  scanf("%d %d", &a, &b);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < M; ++i) {
    scanf("%d", &B[i]);
  }
  if (A[a - 1] < B[0]) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
