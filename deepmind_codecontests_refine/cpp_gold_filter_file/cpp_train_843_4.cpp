#include <bits/stdc++.h>
using namespace std;
char S[100005], T[100005];
int P[100005], Aux[200005], Z[200005];
int N, M;
long long Cnt[100005], Mars[200005];
void Read() {
  scanf("%s", S + 1);
  scanf("%s", T + 1);
  N = strlen(S + 1);
  M = strlen(T + 1);
  for (int i = 1; i <= M; i++) Aux[i] = T[i];
  for (int i = M + 1; i <= N + M; i++) Aux[i] = S[i - M];
}
void buildP() {
  P[1] = 0;
  int q = 0;
  for (int i = 2; i <= M; i++) {
    while (q != 0 && T[q + 1] != T[i]) q = P[q];
    if (T[q + 1] == T[i]) q++;
    P[i] = q;
  }
}
int expand(int left, int right) {
  int ans = 0;
  while (right <= M + N && Aux[left] == Aux[right]) ++left, ++right, ++ans;
  return ans;
}
void buildZ() {
  int L = 0, R = 0;
  Z[1] = N + M;
  for (int i = 2; i <= N + M; i++) {
    if (R < i) {
      Z[i] = expand(1, i);
      L = i;
      R = i + Z[i] - 1;
    } else {
      int aux = i - L + 1;
      if (Z[aux] + i - 1 < R) {
        Z[i] = Z[aux];
      } else {
        Z[i] = R - i + 1 + expand(R - i + 2, R + 1);
        L = i;
        R = i + Z[i] - 1;
      }
    }
  }
}
void precalcCnt() {
  for (int i = 2; i <= M; i++) {
    int nextP = P[i];
    if (nextP > 0) Cnt[i - nextP]++;
  }
}
void precalcMars() {
  for (int i = M + 2; i <= M + N; i++) {
    Mars[Z[i] + 1]--;
    Mars[1]++;
  }
  for (int i = 1; i <= M; i++) {
    Mars[i] += Mars[i - 1];
  }
}
void Solve() {
  long long ans = 1LL * N * M;
  for (int i = 1; i <= M; i++) {
    if (P[i] == 0) continue;
    ans -= Mars[i - P[i]];
  }
  printf("%I64d\n", ans);
}
int main() {
  Read();
  buildP();
  buildZ();
  precalcCnt();
  precalcMars();
  Solve();
  return 0;
}
