#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 100001;
int a, b, n;
map<pair<int, int>, int> m;
bool check(int x, int y) {
  long long ans = 1;
  for (int i = 1; i <= y; i++) {
    ans *= (long long)x;
    if (ans >= n) return 1;
  }
  return 0;
}
int dfs(int x, int y) {
  if (m.find(pair<int, int>(x, y)) != m.end()) return m[pair<int, int>(x, y)];
  if (x == 1 && check(2, y)) return m[pair<int, int>(x, y)] = 2;
  if (y == 1 && check(x, 2)) {
    if ((n - a) & 1)
      return m[pair<int, int>(x, y)] = 0;
    else
      return m[pair<int, int>(x, y)] = 1;
  }
  if (check(x, y)) return m[pair<int, int>(x, y)] = 1;
  int t1 = check(x + 1, y), t2 = check(x, y + 1);
  if (t1 && t2) return m[pair<int, int>(x, y)] = 0;
  if (t1 == 0) t1 = dfs(x + 1, y);
  if (t2 == 0) t2 = dfs(x, y + 1);
  if (t1 == 0 || t2 == 0) return m[pair<int, int>(x, y)] = 1;
  if (t1 == 2 || t2 == 2) return m[pair<int, int>(x, y)] = 2;
  return m[pair<int, int>(x, y)] = 0;
}
int main() {
  while (~scanf("%d%d%d", &a, &b, &n)) {
    if (check(a + 1, b) && check(a, b + 1))
      printf("Stas\n");
    else if (b == 1 && check(a, 2)) {
      if ((n - a) & 1)
        printf("Stas\n");
      else
        printf("Masha\n");
    } else {
      m.clear();
      int ans = dfs(a, b);
      if (ans == 0)
        printf("Stas\n");
      else if (ans == 1)
        printf("Masha\n");
      else
        printf("Missing\n");
    }
  }
  return 0;
}
