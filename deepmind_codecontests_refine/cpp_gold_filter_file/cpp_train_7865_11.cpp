#include <bits/stdc++.h>
using namespace std;
const int MN = 2000010;
vector<int> pr;
int pchk[MN];
void Sieve() {
  for (int i = 2; i < MN; i++) {
    if (!pchk[i]) {
      pr.push_back(i);
    }
    for (int j = 0; j < pr.size() && i * pr[j] < MN; j++) {
      pchk[i * pr[j]] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}
int N, X;
int A[100010], chk[MN];
int main() {
  Sieve();
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  sort(A, A + N);
  if (X == 2) {
    printf("0");
    return 0;
  }
  if (N == 0) {
    printf("-1");
    return 0;
  }
  if (A[0] == 1) {
    printf("1");
    return 0;
  }
  if (X >= MN) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < N; i++)
    if (A[i] < X) {
      chk[A[i]] = 1;
    }
  int cnt = 0;
  for (int i = 0; i < pr.size(); i++)
    if (pr[i] < X) {
      if (!chk[pr[i]]) {
        printf("-1");
        return 0;
      }
      cnt++;
    }
  printf("%d", cnt);
}
