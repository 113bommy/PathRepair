#include <bits/stdc++.h>
using namespace std;
int memo[105][105];
vector<int> de, at;
int C[105];
int N, M, pw;
string tp;
int dp(int X, int Y) {
  if (X < 0 || Y < 0) return 0;
  if (memo[X][Y] != -1) return memo[X][Y];
  int res = dp(X, Y - 1);
  if (C[X] > at[Y]) res = max(res, dp(X - 1, Y - 1) + C[X] - at[Y]);
  return memo[X][Y] = res;
}
int greedy() {
  vector<int> remnant, T;
  int pt = 0, res = 0;
  for (auto def : de) {
    if (pt == M) return 0;
    while (C[pt] <= def) {
      T.push_back(C[pt]);
      pt++;
      if (pt == M) return 0;
    }
    pt++;
  }
  for (; pt < M; pt++) T.push_back(C[pt]);
  pt = 0;
  for (auto atc : at) {
    if (pt == T.size()) return 0;
    while (T[pt] < atc) {
      remnant.push_back(T[pt]);
      pt++;
      if (pt == T.size()) return 0;
    }
    res += T[pt] - atc;
    pt++;
  }
  for (; pt < T.size(); pt++) remnant.push_back(T[pt]);
  for (auto i : remnant) res += i;
  return res;
}
int main() {
  memset(memo, -1, sizeof(memo));
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> tp >> pw;
    if (tp == "ATK") {
      at.push_back(pw);
    } else
      de.push_back(pw);
  }
  sort(at.begin(), at.end());
  sort(de.begin(), de.end());
  for (int i = 0; i < M; i++) {
    cin >> C[i];
  }
  sort(C, C + M);
  int ans = max(dp(M - 1, at.size() - 1), greedy());
  cout << ans << "\n";
}
