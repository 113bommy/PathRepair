#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int A[100000];
  char S[100000 + 1];
  int sum[100000];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%s", S);
  sum[0] = A[0];
  int maxbit = 0;
  int bitsum = (S[0] == '1' ? A[0] : 0);
  for (int i = 1; i < N; i++) {
    sum[i] = sum[i - 1] + A[i];
    if (S[i] == '1') {
      maxbit = i;
      bitsum += A[i];
    }
  }
  int p_max = bitsum;
  int summaxbit = sum[maxbit];
  for (int i = maxbit; i >= 0; i--) {
    if (S[i] == '1') {
      p_max = max(summaxbit - A[i], p_max);
    } else {
      summaxbit -= A[i];
    }
  }
  printf("%d\n", p_max);
}
