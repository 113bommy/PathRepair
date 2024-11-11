#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
int h, w, tot;
char G[505][505];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
bool check(int i0, int j0) {
  if (G[i0][j0] != '*') return false;
  int cnt = 1;
  for (int d = 0; d < 4; d++) {
    int i = i0 + di[d];
    int j = j0 + dj[d];
    if (G[i][j] != '*') return false;
    while (i >= 1 && i <= h && j <= w && j >= 1) {
      if (G[i][j] != '*') break;
      cnt++;
      i += di[d];
      j += dj[d];
    }
  }
  return cnt == tot;
}
int main() {
  cin >> h >> w;
  for (int i = (1); i <= (h); ++i) scanf("%s", G[i] + 1);
  for (int i = (1); i <= (h); ++i)
    for (int j = (1); j <= (w); ++j) tot += G[i][j] == '*';
  for (int i = (2); i <= (h - 1); ++i)
    for (int j = (2); j <= (w - 1); ++j)
      if (check(i, j)) return puts("YES"), 0;
  puts("NO");
}
