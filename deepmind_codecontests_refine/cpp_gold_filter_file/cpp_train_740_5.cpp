#include <bits/stdc++.h>
namespace io {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
}  // namespace io
using namespace io;
using namespace std;
const int N = 1010;
int n = read(), cnt[N + 1];
int a[30][30];
vector<pair<int, int> > v[5];
int main() {
  for (int i = 1, x; i <= n * n; ++i) x = read(), cnt[x]++;
  for (int i = (0); i < ((n + 1) / 2); ++i)
    for (int j = (0); j < ((n + 1) / 2); ++j) {
      if (i != n - i - 1 && j != n - j - 1)
        v[4].push_back(make_pair(i, j));
      else if ((i != n - i - 1) ^ (j != n - j - 1))
        v[2].push_back(make_pair(i, j));
      else
        v[1].push_back(make_pair(i, j));
    }
  for (int s = (4); s >= (1); --s) {
    int cur = 1;
    if (s == 3) continue;
    for (int i = 0, len = v[s].size(); i < len; ++i) {
      int x = v[s][i].first, y = v[s][i].second;
      while (cur < N && cnt[cur] < s) ++cur;
      if (cur == N) return puts("NO"), 0;
      a[x][y] = a[n - x - 1][y] = a[x][n - y - 1] = a[n - x - 1][n - y - 1] =
          cur;
      cnt[cur] -= s;
    }
  }
  puts("YES");
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) printf("%d ", a[i][j]);
    puts("");
  }
}
