#include <bits/stdc++.h>
using namespace std;
inline int NWD(int a, int b) {
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
using P = pair<int, int>;
char buf[2002][2002];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", buf[i] + 1);
  }
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j)
      if ('.' != buf[i][j]) buf[i][j] = 0;
  const P neighbours[]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  set<P> ones;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (0 != buf[i][j]) {
        buf[i][j] = 0;
        for (const P &p : neighbours)
          if (0 != buf[i + p.first][j + p.second]) ++buf[i][j];
        if (0 == buf[i][j]) {
          puts("Not unique");
          return 0;
        }
        if (1 == buf[i][j]) ones.insert({i, j});
      }
    }
  while (ones.size()) {
    const P one = *ones.begin();
    ones.erase(ones.begin());
    P two;
    if (buf[one.first + 1][one.second] && buf[one.first + 1][one.second] < 10) {
      buf[one.first][one.second] = '^';
      buf[one.first + 1][one.second] = 'v';
      two = {one.first + 1, one.second};
    } else if (buf[one.first - 1][one.second] &&
               buf[one.first - 1][one.second] < 10) {
      buf[one.first][one.second] = 'v';
      buf[one.first - 1][one.second] = '^';
      two = {one.first - 1, one.second};
    } else if (buf[one.first][one.second + 1] &&
               buf[one.first][one.second + 1] < 10) {
      buf[one.first][one.second] = '<';
      buf[one.first][one.second + 1] = '>';
      two = {one.first, one.second + 1};
    } else if (buf[one.first][one.second - 1] &&
               buf[one.first][one.second - 1] < 10) {
      buf[one.first][one.second] = '>';
      buf[one.first][one.second - 1] = '<';
      two = {one.first, one.second - 1};
    } else {
      puts("Not unique");
      return 0;
    }
    ones.erase(two);
    for (const P &p : neighbours)
      if (buf[two.first + p.first][two.second + p.second] &&
          buf[two.first + p.first][two.second + p.second] < 10) {
        buf[two.first + p.first][two.second + p.second]--;
        if (buf[two.first + p.first][two.second + p.second] == 1)
          ones.insert({two.first + p.first, two.second + p.second});
      }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) switch (buf[i][j]) {
        case 0:
        case '<':
        case '>':
        case '^':
        case 'v':
          break;
        default:
          puts("Not unique");
          return 0;
      }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", buf[i][j] ? buf[i][j] : '*');
    puts("");
  }
  return 0;
}
