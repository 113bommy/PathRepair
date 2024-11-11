#include <bits/stdc++.h>
using namespace std;
int N;
int X[400000];
int MX[400000], MN[400000];
signed long long ret;
signed long long dp(int L, int R) {
  if (L >= R) return 0;
  if (L + 1 == R) return 1;
  if (L + 2 == R) return 2 + (abs(X[L] - X[L + 1]) == 1);
  int M = (L + R) / 2, i, x1, x2;
  signed long long ret = dp(L, M) + dp(M, R);
  MX[M] = MN[M] = X[M];
  MX[M - 1] = MN[M - 1] = X[M - 1];
  for (i = M - 2; i >= L; i--)
    MX[i] = max(MX[i + 1], X[i]), MN[i] = min(MN[i + 1], X[i]);
  for (i = M + 1; i < R; i++)
    MX[i] = max(MX[i - 1], X[i]), MN[i] = min(MN[i - 1], X[i]);
  for (i = L; i < M; i++) {
    int num = MX[i] - MN[i];
    if (i + num >= M && i + num < R && MX[i + num] < MX[i] &&
        MN[i + num] > MN[i])
      ret++;
  }
  for (i = M; i < R; i++) {
    int num = MX[i] - MN[i];
    if (i - num < M && i - num >= L && MX[i - num] < MX[i] &&
        MN[i - num] > MN[i])
      ret++;
  }
  map<int, int> mm;
  for (i = M - 1, x1 = x2 = M; i >= L; i--) {
    while (x1 < R && MN[x1] > MN[i]) mm[MX[x1] - x1]++, x1++;
    while (x2 < x1 && MX[x2] < MX[i]) mm[MX[x2] - x2]--, x2++;
    ret += mm[MN[i] - i];
  }
  mm.clear();
  for (i = M - 1, x1 = x2 = M; i >= L; i--) {
    while (x1 < R && MX[x1] < MX[i]) mm[x1 + MN[x1]]++, x1++;
    while (x2 < x1 && MN[x2] > MN[i]) mm[x2 + MN[x2]]--, x2++;
    ret += mm[i + MX[i]];
  }
  return ret;
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  for (i = 0; i < N; i++) cin >> x >> y, X[x] = y;
  cout << dp(1, N + 1) << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < argc - 1; i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < s.size(); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
