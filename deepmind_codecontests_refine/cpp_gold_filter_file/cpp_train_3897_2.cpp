#include <bits/stdc++.h>
using namespace std;
long long INF = (1LL << 60);
int N, K;
long long A[4000002];
int ST[4000002];
int P1[4000002], P2[4000002], pnow;
long long B[4000002];
set<pair<long long, int> > S;
set<int> P;
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N; ++i) {
    if (ST[0] >= 2 && A[i] < A[ST[ST[0]]]) {
      ++pnow;
      P1[pnow] = ST[1];
      P2[pnow] = ST[ST[0]];
    }
    if (A[i] < A[ST[ST[0]]]) ST[0] = 0;
    ST[++ST[0]] = i;
  }
  if (ST[0] >= 2) {
    ++pnow;
    P1[pnow] = ST[1];
    P2[pnow] = ST[ST[0]];
  }
  B[++B[0]] = INF;
  long long result = 0;
  for (int i = 1; i <= pnow; ++i) {
    if (i != 1) B[++B[0]] = A[P2[i - 1]] - A[P1[i]];
    B[++B[0]] = A[P2[i]] - A[P1[i]];
    result += B[B[0]];
  }
  B[++B[0]] = INF;
  for (int i = 1; i <= B[0]; ++i) {
    S.insert(make_pair(B[i], i));
    P.insert(i);
  }
  while (pnow > K) {
    auto now = (*S.begin());
    long long val = now.first, wh = now.second;
    S.erase(S.begin());
    P.erase(wh);
    auto it1 = P.lower_bound(wh), it2 = it1;
    --it1;
    B[*it1] += B[*it2];
    B[*it1] -= val;
    S.erase(make_pair(B[*it1] - B[*it2] + val, *it1));
    S.insert(make_pair(B[*it1], *it1));
    S.erase(make_pair(B[*it2], *it2));
    P.erase(*it2);
    result -= val;
    --pnow;
  }
  cout << result << '\n';
}
