#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> A, B;
int main() {
  scanf("%d %d", &N, &M);
  if (N == 1)
    A.push_back(1);
  else if (N == 2) {
    A.push_back(3);
    A.push_back(4);
  } else {
    for (int i = 0; i < N - 1; i++) A.push_back(2);
    A.push_back(N - 2);
  }
  if (M == 1)
    B.push_back(1);
  else if (M == 2) {
    B.push_back(3);
    B.push_back(4);
  } else {
    for (int i = 0; i < M - 1; i++) B.push_back(2);
    B.push_back(M - 2);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", A[i] * B[j]);
    }
    printf("\n");
  }
}
