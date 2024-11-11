#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, r, c;
string w[MAXN];
int l[MAXN];
int s[MAXN];
int t[MAXN];
int fa[MAXN][21];
int x[MAXN];
int main() {
  cin >> n >> r >> c;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) l[i] = w[i].length() + 1;
  c++;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + l[i];
  for (int i = 1; i <= n; i++) {
    int L = i - 1, R = n;
    while (L < R) {
      int mid = (L + R + 1) / 2;
      if (s[mid] - s[i - 1] <= c)
        L = mid;
      else
        R = mid - 1;
    }
    t[i] = L;
  }
  for (int i = 1; i <= n; i++) fa[i][0] = t[i] + 1;
  fa[n + 1][0] = n + 1;
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n + 1; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = 0; j <= 20; j++)
      if ((1 << j) & r) p = fa[p][j];
    x[i] = p;
  }
  int ans = -10000, o = 1;
  for (int i = 1; i <= n; i++)
    if (x[i] - i > ans) ans = x[i] - i, o = i;
  int now = 0;
  bool flag = false;
  for (int i = o; i < x[o]; i++) {
    if (now + l[i] > c) {
      cout << endl;
      now = 0;
      flag = false;
    }
    now += l[i];
    if (flag) cout << ' ';
    cout << w[i];
    flag = true;
  }
  return 0;
}
