#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000 + 7;
const int N = 200 + 10;
struct re {
  int x, y;
};
int n, k, a[N], f[N][N][N], same[N][N], p[N];
string s;
int getval(int x, int g) {
  if (x == k) return k;
  if (a[x + 1] == g) return x + 1;
  if (p[x]) return p[x];
  return (g == a[1]);
}
int cal(int x, int s, int y) {
  if (s < 0) return 0;
  if (x == n * 2) return (s == 0 && y == k);
  if (f[x][s][y] > -1) return f[x][s][y];
  int res = 0;
  res += cal(x + 1, s + 1, getval(y, 1));
  res += cal(x + 1, s - 1, getval(y, -1));
  res %= M;
  f[x][s][y] = res;
  return res;
}
int main() {
  cin >> n;
  cin >> s;
  k = s.size();
  for (int i = (1); (i <= (k)); ++i) {
    if (s[i - 1] == '(')
      a[i] = 1;
    else
      a[i] = -1;
  }
  for (int i = (1); (i <= (k)); ++i) {
    for (int j = (1); (j <= (i - 1)); ++j)
      if (a[i] == a[j]) same[i][j] = same[i - 1][j - 1] + 1;
  }
  for (int i = (1); (i <= (k - 1)); ++i) {
    for (int j = (1); (j <= (i - 1)); ++j)
      if (same[i][j] == j && a[i + 1] != a[j + 1]) p[i] = j;
  }
  memset(f, 255, sizeof(f));
  int res = cal(0, 0, 0);
  cout << res;
}
