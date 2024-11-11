#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const size_t MAX_N = 35;
const size_t LOG_N = 4;
int N, M;
int inp[MAX_N + 1];
set<int> sA, sB;
void genSets(set<int>& s, int offset, int limitShift) {
  int limit = 1 << limitShift;
  for (int i = 1; i < limit; i++) {
    int sum = 0;
    for (int b = 0; b < limitShift; b++)
      sum = (sum + inp[(((1 << b) & i) >> b) * (offset + b + 1)]) % M;
    s.insert(sum);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  inp[0] = 0;
  sA.insert(0);
  sB.insert(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> inp[i + 1];
  int lower = floor(static_cast<double>(N / 2)),
      upper = ceil(static_cast<double>(N / 2));
  genSets(sA, 0, lower);
  genSets(sB, lower, upper);
  int maxAns = -1;
  for (int s : sA) {
    auto compBest = sB.lower_bound(M - s);
    if (compBest == sB.end() || *compBest >= M - s) compBest--;
    maxAns = max(s + *compBest, maxAns);
  }
  cout << maxAns;
  return 0;
}
