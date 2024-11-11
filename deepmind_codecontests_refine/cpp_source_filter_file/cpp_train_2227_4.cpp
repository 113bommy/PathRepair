#include <bits/stdc++.h>
using namespace std;
int N;
pair<signed long long, signed long long> P[100200];
signed long long miy[100200][2], may[100200][2];
int ok(signed long long w) {
  int x, y;
  y = 0;
  for (x = 0; x < N; x++) {
    while (y < N && P[y].first <= P[x].first + w) y++;
    if (x == 0 && y == N) return 1;
    if (x == 0 && may[y][1] - miy[y][1] <= w) return 1;
    if (x > 0 && y == N && may[x - 1][0] - miy[x - 1][0] <= w) return 1;
    if (x > 0 && y < N &&
        max(may[x - 1][0], may[y][1]) - min(miy[x - 1][0], miy[y][1]) <= w)
      return 1;
  }
  return 0;
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> x >> y;
    P[i].first = x + y;
    P[i].second = x - y;
  }
  sort(P, P + N);
  miy[0][0] = may[0][0] = P[0].second;
  for (i = 1; i < N; i++) miy[i][0] = min(miy[i - 1][0], P[i].second);
  for (i = 1; i < N; i++) may[i][0] = max(may[i - 1][0], P[i].second);
  miy[N - 1][1] = may[N - 1][1] = P[N - 1].second;
  for (i = N - 2; i >= 0; i--) miy[i][1] = min(miy[i + 1][1], P[i].second);
  for (i = N - 2; i >= 0; i--) may[i][1] = max(may[i + 1][1], P[i].second);
  signed long long ret = 0;
  if (ok(0)) return (void)printf("0\n");
  for (i = 32; i >= 0; i--)
    if (ok(ret + (1LL << i)) == 0) ret += 1LL << i;
  (void)printf("%lf\n", ret * 1.0);
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
