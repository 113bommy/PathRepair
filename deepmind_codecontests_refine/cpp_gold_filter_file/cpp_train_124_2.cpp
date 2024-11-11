#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, k, dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0},
             dz[6] = {0, 0, 0, 0, 1, -1}, a[N];
vector<int> vec[N];
void No() {
  cout << -1;
  exit(0);
}
int id(int x, int y, int z) { return (x - 1) * m * k + (y - 1) * k + z; }
bool in(int x, int y, int z) {
  return 1 <= x && x <= n && 1 <= y && y <= m && 1 <= z && z <= k;
}
void erase(int, int, int);
void insert(int d, int x, int y, int z, int c) {
  if (!in(x, y, z)) {
    if (c) No();
    return;
  }
  int t = id(x, y, z);
  if (!c) {
    if (a[t] > 0) erase(x, y, z);
    a[t] = 0;
    insert(d, x + dx[d], y + dy[d], z + dz[d], c);
  } else if (!~a[t] || a[t] == c) {
    a[t] = c;
    vec[t].push_back(d);
  } else if (!a[t])
    insert(d, x + dx[d], y + dy[d], z + dz[d], c);
  else
    erase(x, y, z), a[t] = 0, insert(d, x + dx[d], y + dy[d], z + dz[d], c);
}
void erase(int x, int y, int z) {
  int t = id(x, y, z);
  while (!vec[t].empty()) {
    int d = vec[t].back();
    vec[t].pop_back();
    insert(d, x + dx[d], y + dy[d], z + dz[d], a[t]);
  }
}
int main() {
  memset(a, -1, sizeof(a));
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) insert(0, 1, i, j, gi());
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) insert(1, n, i, j, gi());
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) insert(2, i, 1, j, gi());
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) insert(3, i, m, j, gi());
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) insert(4, i, j, 1, gi());
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) insert(5, i, j, k, gi());
  for (int i = 1; i <= n * m * k; i++) cout << max(0, a[i]) << ' ';
  return 0;
}
