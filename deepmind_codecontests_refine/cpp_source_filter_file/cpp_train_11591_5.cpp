#include <bits/stdc++.h>
using namespace std;
struct CALL {
  int start;
  int end;
  CALL(){};
  bool operator<(const CALL& v) const { return start < v.start; }
  int End() { return start + end; }
};
CALL Calls[10000];
int End[5000][5000];
int fEnd(int call, int skip) {
  if (skip < 0) return 864000;
  if (call < 0) return 1;
  if (End[call][skip]) return End[call][skip];
  int without_skip = fEnd(call - 1, skip) + Calls[call].end;
  if (without_skip < Calls[call].End()) without_skip = Calls[call].End();
  int with_skip = fEnd(call - 1, skip - 1);
  if (without_skip < with_skip) {
    return End[call][skip] = without_skip;
  } else {
    return End[call][skip] = with_skip;
  }
  return End[call][skip];
}
int nbCalls;
int nbSkips;
int main() {
  scanf("%d %d\n", &nbCalls, &nbSkips);
  for (int call = 0; call < nbCalls; call++)
    scanf("%d %d", &Calls[call].start, &Calls[call].end);
  Calls[nbCalls++].start = 86400;
  sort(Calls, Calls + nbCalls);
  int ans = 0;
  for (int skip = 0; skip <= nbSkips; skip++)
    for (int call = 0; call + skip < nbCalls; call++) {
      int sleep = Calls[call + skip].start - fEnd(call - 1, nbSkips - skip);
      if (sleep > ans) ans = sleep;
    }
  printf("%d\n", ans);
  return 0;
}
