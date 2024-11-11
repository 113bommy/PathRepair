#include <bits/stdc++.h>
using namespace std;
const int N = 200006;
int n, ans = 1;
vector<int> p[N], c[N], e[N];
bool flag, v[N];
inline void update(int x, int y) {
  for (unsigned int i = 0; i < p[x].size(); i++)
    for (unsigned int j = 0; j < p[y].size(); j++)
      if (p[x][i] == p[y][j]) {
        ans = max(ans, c[x][i] + c[y][j]);
        c[x][i] = max(c[x][i], c[y][j] + 1);
      }
}
void dp(int x) {
  v[x] = 1;
  for (unsigned int i = 0; i < e[x].size(); i++) {
    int y = e[x][i];
    if (v[y]) continue;
    dp(y);
    update(x, y);
  }
}
inline void divide(int x, int t) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      p[t].push_back(i);
      c[t].push_back(1);
      while (x % i == 0) x /= i;
    }
  if (x > 1) {
    p[t].push_back(x);
    c[t].push_back(1);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    divide(x, i);
    if (x != 1) flag = 0;
  }
  if (flag) {
    puts("0");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dp(1);
  cout << ans << endl;
  return 0;
}
