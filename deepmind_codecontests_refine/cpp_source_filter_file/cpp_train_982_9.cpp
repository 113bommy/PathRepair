#include <bits/stdc++.h>
using namespace std;
int N, D, K;
int main() {
  scanf("%d%d%d", &N, &D, &K);
  vector<vector<int> > A(N, vector<int>(D, 0));
  for (int i = 0; i < N; i++) {
    int x = i;
    for (int j = D - 1; j >= 0; j--) {
      A[i][j] = x % K;
      x /= K;
    }
    if (x) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < N; j++) printf("%d ", A[j][i] + 1);
    printf("\n");
  }
}
