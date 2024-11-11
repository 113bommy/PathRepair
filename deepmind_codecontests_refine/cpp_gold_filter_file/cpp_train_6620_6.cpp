#include <bits/stdc++.h>
using namespace std;
const pair<int, int> DD[] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                             {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
template <class T>
T smin(T &a, T b) {
  if (a > b) a = b;
  return a;
}
template <class T>
T smax(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int main(void) {
  srand(time(0));
  cout << fixed << setprecision(7);
  cerr << fixed << setprecision(7);
  int n, k;
  cin >> n >> k;
  static int D[1 << 10][1 << 12];
  static char s[1 << 20];
  cin >> (s + 1);
  D[0][k + 1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1 + (i != n); j <= k + k + 1 - (i != n); ++j) {
      if (s[i] == 'W' || s[i] == '?') D[i][j] |= D[i - 1][j - 1];
      if (s[i] == 'L' || s[i] == '?') D[i][j] |= D[i - 1][j + 1];
      if (s[i] == 'D' || s[i] == '?') D[i][j] |= D[i - 1][j];
    }
  }
  if (!D[n][1] && !D[n][k + k + 1]) return puts("NO") * 0;
  string answer;
  int cnt = D[n][1] ? 1 : k + k + 1;
  for (int i = n; i; --i) {
    if ((s[i] == 'W' || s[i] == '?') && D[i - 1][cnt - 1])
      answer += 'W', --cnt;
    else if ((s[i] == 'L' || s[i] == '?') && D[i - 1][cnt + 1])
      answer += 'L', ++cnt;
    else
      answer += 'D';
  }
  reverse(answer.begin(), answer.end());
  cout << answer << '\n';
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
