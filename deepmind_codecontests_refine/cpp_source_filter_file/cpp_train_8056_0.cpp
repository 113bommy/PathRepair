#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long f[40][20][20], p[20];
int to[40][20][20];
long long dfs(int cur, int h, int m) {
  if (cur == 2 * n) return 0;
  long long &res = f[cur][h][m];
  int &go = to[cur][h][m];
  if (res != -1) return res;
  res = 0;
  if (h < n) {
    long long ret = dfs(cur + 1, h + 1, m) + (s[cur] - '0') * p[n - h - 1];
    if (res < ret) res = ret, go = 1;
  }
  if (m < n) {
    long long ret = dfs(cur + 1, h, m + 1) + (s[cur] - '0') * p[n - m - 1];
    if (res < ret) res = ret, go = 2;
  }
  return res;
}
void print(int cur, int h, int m) {
  while (cur < 2 * n) {
    cout << (to[cur][h][m] == 1 ? 'H' : 'M');
    to[cur][h][m] == 1 ? h++ : m++;
    cur++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 10;
  memset(f, -1, sizeof(f));
  dfs(0, 0, 0);
  print(0, 0, 0);
  return 0;
}
