#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char s[7][7];
const char mv[4] = {'L', 'R', 'U', 'D'};
const long long lf[13] = {3, 0, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1, 3};
const long long uf[13] = {0, 2, 0, 3, 0, 2, 0, 3, 0, 2, 0, 3, 0};
inline char sc(long long x) {
  if (x < 10)
    return x + 48;
  else
    return x + 65 - 10;
}
vector<pair<long long, long long> > Ans;
int main() {
  for (long long i = (0); i <= (5); ++i) scanf("%s", s[i]);
  for (long long i = (0); i <= (5); ++i)
    for (long long j = (0); j <= (5); ++j) {
      if (sc(i * 6 + j) == s[i][j])
        continue;
      else {
        long long x, y;
        for (long long k = (0); k <= (5); ++k)
          for (long long l = (0); l <= (5); ++l)
            if (s[k][l] == sc(i * 6 + j)) {
              x = k, y = l;
              break;
            }
        while (y > j)
          Ans.push_back(make_pair(0, x * 6 + y - 1)),
              swap(s[x][y], s[x][y - 1]), y--;
        while (y < j)
          Ans.push_back(make_pair(0, x * 6 + y)), swap(s[x][y], s[x][y + 1]),
              y++;
        while (x > i)
          Ans.push_back(make_pair(1, (x - 1) * 6 + y)),
              swap(s[x][y], s[x - 1][y]), x--;
        while (x < i)
          Ans.push_back(make_pair(1, x * 6 + y)), swap(s[x][y], s[x + 1][y]),
              x++;
      }
    }
  cout << Ans.size() * 13 << endl;
  for (long long i = (0); i < (Ans.size()); ++i) {
    if (Ans[i].first == 0)
      for (long long j = (0); j <= (12); ++j)
        printf("%c%lld\n", mv[lf[j]],
               (lf[j] >= 2 ? Ans[i].second / 6 : Ans[i].second % 6) + 1);
    else
      for (long long j = (0); j <= (12); ++j)
        printf("%c%lld\n", mv[uf[j]],
               (uf[j] >= 2 ? Ans[i].second / 6 : Ans[i].second % 6) + 1);
  }
}
