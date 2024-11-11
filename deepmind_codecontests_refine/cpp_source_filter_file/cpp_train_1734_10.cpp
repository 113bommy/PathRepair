#include <bits/stdc++.h>
using namespace std;
const int M = 18;
int k, n, m, x;
bool a[M][1 << M];
int c[M];
vector<int> cur, Ans;
void Dfs(int x) {
  int l = -c[x], r = c[x], val = c[x];
  bool fl = 0;
  for (int i = l; i <= r; i++)
    if (i && a[x][i + val]) {
      fl = 1;
      break;
    }
  if (!fl) {
    if (cur.size() < Ans.size()) Ans = cur;
    return;
  }
  if (x == M) return;
  fl = 0;
  for (int i = l; i <= r; i++)
    if ((i & 1) && a[x][i + val]) {
      fl = 1;
      break;
    }
  if (!fl) {
    for (int i = l / 2; i <= r / 2; i++) a[x + 1][i + c[x + 1]] = 0;
    for (int i = l; i <= r; i++)
      if (a[x][i + val]) a[x + 1][i / 2 + c[x + 1]] = 1;
    Dfs(x + 1);
  } else {
    for (int i = l / 2; i <= r / 2; i++) a[x + 1][i + c[x + 1]] = 0;
    for (int i = l; i <= r; i++)
      if (a[x][i + val]) a[x + 1][(i & 1 ? (i - 1) / 2 : i / 2) + c[x + 1]] = 1;
    cur.push_back(1 << x);
    Dfs(x + 1);
    cur.pop_back();
    for (int i = l / 2; i <= r / 2; i++) a[x + 1][i + c[x + 1]] = 0;
    for (int i = l; i <= r; i++)
      if (a[x][i + val]) a[x + 1][(i & 1 ? (i + 1) / 2 : i / 2) + c[x + 1]] = 1;
    cur.push_back(-(1 << x));
    Dfs(x + 1);
    cur.pop_back();
  }
}
int main() {
  scanf("%d", &n);
  c[M - 1] = 1;
  for (int i = M - 2; i >= 0; i--) c[i] = c[i + 1] << 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x) a[0][x + c[0]] = 1;
  }
  for (int i = 1; i <= 20; i++) Ans.push_back(0);
  Dfs(0);
  cout << Ans.size() << endl;
  for (int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
  return 0;
}
