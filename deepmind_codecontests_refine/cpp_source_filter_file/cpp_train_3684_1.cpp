#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int INF = 1 << 29;
const int MAXN = 505;
int n;
int M[MAXN][MAXN];
int R[MAXN];
long long A[MAXN];
int main(int argc, char** argv) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &M[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &R[n - i - 1]);
    R[n - i - 1]--;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        M[R[i]][R[j]] = min(M[R[i]][R[j]], M[R[i]][R[k]] + M[R[k]][R[j]]);
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        A[n - k - 1] += M[R[i]][R[j]];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d", A[i]);
  }
  printf("\n");
  return 0;
}
