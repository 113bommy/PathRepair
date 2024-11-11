#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
const int md = 1e9 + 7;
const int inf = 1e9 + 3;
int n, m;
string a[N];
int b[N];
bool cmp(int x, int y) {
  for (int i = 0; i < m; ++i) {
    if (a[x][i] != a[y][i]) {
      if (i & 1) {
        return a[x][i] > a[i][i];
      } else {
        return a[x][i] < a[y][i];
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = i;
  sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
}
