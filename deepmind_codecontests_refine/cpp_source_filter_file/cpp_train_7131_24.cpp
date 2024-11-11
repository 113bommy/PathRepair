#include <bits/stdc++.h>
using namespace std;
int N, K, S;
int Q[1010];
signed long long from[151][150 * 160], to[151][150 * 160];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> K >> S;
  for (i = 0; i < N; i++) cin >> Q[i];
  if (S > N * (N - 1) / 2 || K == N) {
    sort(Q, Q + N);
    int tot = 0;
    for (i = 0; i < K; i++) tot += Q[i];
    return (void)printf("%d\n", tot);
  }
  for (x = 0; x < N; x++)
    for (y = 0; y < 150 * 160; y++) from[x][y] = 1LL << 60;
  from[0][0] = 0;
  for (i = N - 1; i >= 0; i--) {
    for (x = K; x >= 0; x--)
      for (y = (150) * (160); y >= 0; y--) to[x][y] = 1LL << 60;
    for (x = K; x >= 0; x--)
      for (y = (150) * (160); y >= 0; y--)
        if (from[x][y] < 1LL << 60) {
          if (x < K) {
            to[x + 1][y] = min(to[x + 1][y], from[x][y] + Q[i]);
          }
          to[x][y + x] = min(to[x][y + x], from[x][y]);
        }
    swap(from, to);
  }
  signed long long mi = 1LL << 60;
  for (i = 0; i < S + 1; i++) mi = min(mi, from[K][i]);
  cout << mi << endl;
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
