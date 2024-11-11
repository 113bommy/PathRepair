#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const double EPS = 1e-6;
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int p[maxn];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool check(int i, int j) {
  int x1 = i / m, y1 = i % m;
  int x2 = j / m, y2 = j % m;
  for (int i = 0; i < (4); ++i) {
    int xx = x1 + dx[i], yy = y1 + dy[i];
    if (xx == x2 && yy == y2) return true;
  }
  return false;
}
bool dfs(int i) {
  if (i == n * m) return true;
  int x = i / m, y = i % m;
  for (int j = i; j < (n * m); ++j) {
    swap(p[i], p[j]);
    if (x && check(p[i], p[(x - 1) * m + y])) continue;
    if (y && check(p[i], p[x * m + y - 1])) continue;
    if (dfs(i + 1)) return true;
    swap(p[i], p[j]);
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n * m); ++i) p[i] = i;
  if (!dfs(0)) return printf("NO\n"), 0;
  puts("YES");
  for (int i = 0; i < (n * m); ++i)
    printf("%d%c", p[i] + 1, (i + 1) % m == 0 ? '\n' : ' ');
  return 0;
}
