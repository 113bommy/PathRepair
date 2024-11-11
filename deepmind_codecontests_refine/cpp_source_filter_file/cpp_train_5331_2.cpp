#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 105;
int n, m, a[N][N];
pair<int, int> ned[N];
vector<int> ans;
bool cmp(pair<int, int> first, pair<int, int> second) {
  return first.first > second.first;
}
signed main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) read(a[i][j]);
  for (int i = 1; i <= n; i++) ans.push_back(i);
  for (int i = 1; i < n; i++) {
    int delta = 0;
    vector<int> cur;
    for (int j = 1; j <= m; j++)
      delta += a[j][n] - a[j][i], ned[j] = pair<int, int>(a[j][n] - a[j][i], j);
    if (delta <= 0) {
      write(0);
      return 0;
    }
    sort(ned + 1, ned + 1 + m, cmp);
    for (int j = 1; j <= m; j++) {
      delta -= ned[j].first;
      cur.push_back(ned[j].second);
      if (cur.size() >= ans.size()) break;
      if (delta <= 0) {
        ans = cur;
        break;
      }
    }
  }
  write(ans.size());
  puts("");
  for (int i = 0; i < ans.size(); i++) write(ans[i]), putchar(' ');
}
