#include <bits/stdc++.h>
using namespace std;
const int NMax = 101000;
int N, M, A[NMax], B[NMax], sa[NMax], sb[NMax], La, Lb, ret[NMax], L;
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    int first;
    scanf("%d", &first);
    A[first]++;
  }
  for (int i = 1; i <= N; i++) {
    int first;
    scanf("%d", &first);
    B[first]++;
  }
  for (int i = M - 1; i >= 0; i--) {
    while (A[i]) {
      sa[La++] = i;
      A[i]--;
    }
    while (B[M - 1 - i]) {
      sb[Lb++] = M - 1 - i;
      B[M - 1 - i]--;
    }
    while (La > 0 && Lb > 0 && sa[La - 1] + sb[Lb - 1] < M) {
      ret[L++] = (sa[La - 1] + sb[Lb - 1]) % M;
      La--;
      Lb--;
    }
  }
  for (int i = 0; i < La; i++) {
    ret[L++] = (sa[i] + sb[Lb - 1]) % M;
    Lb--;
  }
  sort(ret, ret + N, cmp);
  for (int i = 0; i < N; i++) printf("%d ", ret[i]);
  puts("");
  return 0;
}
