#include <bits/stdc++.h>
using namespace std;
int N;
string cards[52];
inline bool compat(int i, int j) {
  return cards[i][0] == cards[j][0] || cards[i][1] == cards[j][1];
}
char memo[52][52][52][52];
char go(int n, int p3, int p2, int p1) {
  if (n == 1) return 1;
  if (n == 2) return compat(p3, p2);
  if (n == 3) return compat(p3, p2) && go(n - 1, p3, p1, -1);
  char& res = memo[n][p3][p2][p1];
  if (res < 0) {
    res = 0;
    if (compat(p3, p2))
      if (go(n - 1, p3, p1, n - 3)) res = 1;
    if (compat(p3, n - 3))
      if (go(n - 1, p2, p1, p3)) res = 1;
  }
  return res;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> cards[i];
  int res = 0;
  if (N == 1)
    res = 1;
  else if (N == 2)
    res = compat(0, 1);
  else {
    memset(memo, -1, sizeof(memo));
    res = go(N - 1, N - 1, N - 2, N - 3);
  }
  cout << (res == 1 ? "YES" : "NO") << endl;
  return 0;
}
