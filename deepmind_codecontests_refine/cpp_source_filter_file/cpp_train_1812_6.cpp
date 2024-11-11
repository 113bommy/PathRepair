#include <bits/stdc++.h>
using namespace std;
int read_num() {
  int num = 0;
  char ch;
  ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  do {
    num = num * 10 + (ch - '0');
    ch = getchar();
  } while (isdigit(ch));
  return num;
}
int m, n;
bool check(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) return true;
  return false;
}
char _graph[333][333];
int graph[333][333];
int main() {
  n = read_num();
  m = read_num();
  int p = read_num();
  for (int i = 0; i < (int)(n); i++) {
    scanf("%s", _graph[i]);
  }
  vector<pair<int, pair<int, int> > > ret;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++)
      if (graph[i][j] == 1) {
        bool boo = true;
        for (int rad = 1; rad <= max(n, m) && boo; rad++) {
          if (check(i - rad, j) && check(i + rad, j) && check(i, j + rad) &&
              check(i, j - rad)) {
            if (_graph[i - rad][j] == '*' && _graph[i + rad][j] == '*' &&
                _graph[i][j + rad] == '*' && _graph[i][j - rad] == '*')
              ret.push_back(make_pair(rad, make_pair(i, j)));
          }
        }
      }
  sort((ret).begin(), (ret).end());
  if (ret.size() < p)
    puts("-1");
  else {
    printf("%d %d\n", ret[p - 1].second.first + 1,
           ret[p - 1].second.second + 1);
    printf("%d %d\n", ret[p - 1].second.first - ret[p - 1].first + 1,
           ret[p - 1].second.second + 1);
    printf("%d %d\n", ret[p - 1].second.first + ret[p - 1].first + 1,
           ret[p - 1].second.second + 1);
    printf("%d %d\n", ret[p - 1].second.first + 1,
           ret[p - 1].second.second - ret[p - 1].first + 1);
    printf("%d %d\n", ret[p - 1].second.first + 1,
           ret[p - 1].second.second + ret[p - 1].first + 1);
  }
  return 0;
}
