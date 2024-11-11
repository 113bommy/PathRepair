#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int p = N / M, d = N % M;
  for (int i = 1; i <= M - d; i++) {
    printf("%d ", p);
  }
  for (int i = 1; i <= d; i++) {
    printf("%d ", p + 1);
  }
  return 0;
}
