#include <bits/stdc++.h>
using namespace std;
const int LN = 12;
int N, M, x, y;
pair<int, int> A[LN], B[LN];
set<int> SA[LN], SB[LN], SR;
int solve(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first && a.second != b.second) return a.first;
  if (a.first == b.second && a.second != b.first) return a.first;
  if (a.first != b.first && a.second == b.second) return a.second;
  if (a.first != b.second && a.second == b.first) return a.second;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> x >> y, A[i] = make_pair(x, y);
  for (int i = 0; i < M; i++) cin >> x >> y, B[i] = make_pair(x, y);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      x = solve(A[i], B[j]);
      if (x == -1) continue;
      SA[i].insert(x);
      SB[i].insert(x);
      SR.insert(x);
    }
  if (SR.size() == 1) return cout << *(SR.begin()), 0;
  for (int i = 0; i < N; i++)
    if (SA[i].size() > 1) return cout << -1, 0;
  for (int i = 0; i < M; i++)
    if (SB[i].size() > 1) return cout << -1, 0;
  cout << 0;
  return 0;
}
