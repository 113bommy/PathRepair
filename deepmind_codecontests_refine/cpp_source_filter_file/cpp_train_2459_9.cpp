#include <bits/stdc++.h>
using namespace std;
const int NMax = 400005;
int N;
long long C, S[NMax], Partial[NMax], Deque[NMax], Res[NMax], PartialR[NMax];
void Read() {
  scanf("%d", &N);
  scanf("%I64d", &C);
  for (int i = 1; i <= N * 2 - 1; i++) {
    scanf("%I64d", &S[i]);
    Partial[i] = Partial[i - 1] + S[i];
  }
}
void Solve() {
  int last = 0, End = 0, Begin = 1;
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    long long res = min(C, S[2 * i - 1]);
    while (last < i && Partial[2 * i - 1] - Partial[2 * (last + 1) - 2] >= C)
      ++last;
    while (Begin <= End && Deque[Begin] <= last) ++Begin;
    if (last > 0) res = max(res, C - PartialR[i - 1] + PartialR[last - 1]);
    if (Begin <= End)
      res = max(res, Partial[2 * i - 1] - Partial[Deque[Begin] * 2 - 2] -
                         PartialR[i - 1] + PartialR[Deque[Begin] - 1]);
    ans += res;
    while (Begin <= End &&
           PartialR[i - 1] - Partial[i * 2 - 2] <
               PartialR[Deque[End] - 1] - Partial[Deque[End] * 2 - 2])
      --End;
    Deque[++End] = i;
    PartialR[i] = PartialR[i - 1] + res;
  }
  printf("%I64d\n", ans);
}
int main() {
  Read();
  Solve();
  return 0;
}
