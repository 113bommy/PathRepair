#include <bits/stdc++.h>
using namespace std;
int w = 0, n, k;
string a, c;
int v[100001][2];
void dfs(int i, bool b) {
  if (i > n) {
    cout << "YES" << '\n';
    exit(0);
  };
  if (i < w) return;
  if (b) {
    if (c[i] == 'X') return;
  } else {
    if (a[i] == 'X') return;
  }
  if (v[i][b]) return;
  v[i][b] = 1;
  w++;
  dfs(i + 1, b);
  dfs(i - 1, b);
  dfs(i + k, !b);
  w--;
}
int main() {
  cin >> n >> k >> a >> c;
  dfs(0, 0);
  {
    cout << "NO" << '\n';
    exit(0);
  };
}
