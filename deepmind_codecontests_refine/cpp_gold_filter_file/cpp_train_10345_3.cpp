#include <bits/stdc++.h>
using namespace std;
char str[110][10010];
long long sum = 0;
pair<int, int> cal(pair<int, int> pos, int h, int m) {
  int l = pos.first, r = pos.first, dir = pos.second;
  int flag = 0;
  while (1) {
    if (flag > 1) return make_pair(-1, 0);
    if (dir == 1) {
      sum += r - l;
      for (; str[h][r] == '.' && str[h + 1][r] != '.' && r < m; ++r, ++sum)
        ;
      if (r == m || str[h][r] == '#')
        ++flag, --r;
      else if (str[h][r] == '+')
        str[h][r] = '.', --r, flag = 0;
      else if (str[h + 1][r] == '.')
        return make_pair(r, dir);
    } else {
      sum += r - l;
      for (; str[h][l] == '.' && str[h + 1][l] != '.' && l >= 0; --l, ++sum)
        ;
      if (l < 0 || str[h][l] == '#')
        ++flag, ++l;
      else if (str[h][l] == '+')
        str[h][l] = '.', ++l, flag = 0;
      else if (str[h + 1][l] == '.')
        return make_pair(l, dir);
    }
    dir = !dir;
  }
}
int main() {
  int n, m;
  pair<int, int> pos = make_pair(0, 1);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", str[i]);
  for (int i = 0; i < n - 1; ++i) {
    pos = cal(pos, i, m);
    ++sum;
    if (pos.first == -1) {
      cout << "Never";
      return 0;
    }
  }
  cout << sum;
  return 0;
}
