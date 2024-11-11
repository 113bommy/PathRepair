#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
char s[maxn][maxn];
struct Point {
  int x, y;
  Point(int a, int b) { x = a, y = b; }
  bool operator<(const Point& t) const {
    if (x == t.x) return y < t.y;
    return x < t.x;
  }
};
vector<Point> a[26];
int check(int p) {
  int n = a[p].size();
  if (a[p][0].x == a[p][n - 1].x) {
    int x = a[p][0].x;
    for (int i = a[p][0].y; i <= a[p][n - 1].y; i++)
      if (s[x][i] != '*' && s[x][i] != p + 'a') return 0;
    for (auto tmp : a[p])
      if (tmp.x != x) return 0;
  } else if (a[p][0].y == a[p][n - 1].y) {
    int y = a[p][0].y;
    for (int i = a[p][0].x; i <= a[p][n - 1].x; i++)
      if (s[i][y] != '*' && s[i][y] != p + 'a') return 0;
    for (auto tmp : a[p])
      if (tmp.y != y) return 0;
  } else
    return 0;
  for (auto tmp : a[p]) s[tmp.x][tmp.y] = '*';
  return 1;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    stack<int> sta;
    cin >> n >> m;
    for (int i = 0; i < 26; i++) a[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == '.') continue;
        int cur = s[i][j] - 'a';
        a[cur].push_back(Point(i, j));
      }
    }
    int flag = 1, p = -1;
    for (int i = 25; i >= 0 && flag; i--) {
      if (a[i].size() == 0) {
        if (p != -1) sta.push(p);
        continue;
      }
      sort(a[i].begin(), a[i].end());
      if (!check(i))
        flag = 0;
      else
        sta.push(i);
      p = i;
    }
    if (!flag) {
      puts("NO");
      continue;
    }
    puts("YES");
    cout << sta.size() << endl;
    while (!sta.empty()) {
      int cur = sta.top();
      sta.pop();
      int len = a[cur].size();
      cout << a[cur][0].x << " " << a[cur][0].y << " ";
      cout << a[cur][len - 1].x << " " << a[cur][len - 1].y << endl;
    }
  }
}
