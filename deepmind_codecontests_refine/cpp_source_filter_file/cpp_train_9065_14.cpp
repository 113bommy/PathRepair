#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
char s[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn], up[maxn][maxn], down[maxn][maxn];
int judgex[maxn][maxn], judgey[maxn][maxn];
struct node {
  int x, y, len;
};
vector<node> vec;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '*') {
        l[i][j] += (l[i][j - 1] + 1);
        up[i][j] += (up[i - 1][j] + 1);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (s[i][j] == '*') {
        r[i][j] += (r[i][j + 1] + 1);
        down[i][j] += (down[i + 1][j] + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int minx = 100000;
      if (s[i][j] == '*') {
        minx = min(min(r[i][j], down[i][j]), min(l[i][j], up[i][j]));
        if (minx > 1) {
          vec.push_back({i, j, minx - 1});
          judgex[i][j - minx + 1]++;
          judgex[i][j + minx]++;
          judgey[i - minx + 1][j]++;
          judgey[i + minx][j]++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      judgex[i][j] += judgex[i][j - 1];
      judgey[i][j] += judgey[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (judgex[i][j] == 0 && judgey[i][j] == 0 && s[i][j] == '*') {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", vec.size());
  for (int i = 0; i < vec.size(); i++) {
    printf("%d %d %d\n", vec[i].x, vec[i].y, vec[i].len);
  }
  return 0;
}
