#include <bits/stdc++.h>
using namespace std;
struct block {
  int x, type;
  block() {}
  block(int x_, int type_) {
    x = x_;
    type = type_;
  }
  bool operator<(block right) const {
    return x < right.x || (x == right.x && type < right.type);
  }
};
vector<block> b;
int mark[200005][2];
char a[200005][2];
int rang[200005];
int dif[200005];
void dfs(int x, int y, int n, int c) {
  mark[x][y] = c;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++)
      if ((i == 0 ^ j == 0) && y + i >= 0 && y + i < 2 && x + j >= 0 &&
          x + j < n && !mark[x + j][y + i])
        dfs(x + j, y + i, n, c);
}
void lem1(int n) {
  int c = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      if (!mark[j][i]) {
        dfs(j, i, n, c);
        c++;
      }
}
void lem2(int k) {
  int last = -1;
  for (int i = 0; i < k; i++) {
    if (i) dif[i] = dif[i - 1];
    if (b[i].type != last) {
      dif[i]++;
      last = b[i].type;
    }
  }
}
int Dif(int x1, int x2) {
  if (x1 > x2) return 0;
  int ans = dif[x2];
  if (x1) {
    ans -= dif[x1 - 1];
    if (b[x1].type == b[x1 - 1].type) ans++;
  }
  return ans;
}
int bs(int x, int k) {
  int low = 0, high = k;
  while (low != high) {
    int mid = (low + high) / 2;
    if (b[mid].x > x)
      high = mid;
    else
      low = mid + 1;
  }
  return low;
}
int main() {
  int n, m, k = 0;
  cin >> n >> m;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[j][i];
      if (a[j][i] == 'X') {
        b.push_back(block(j, i));
        k++;
        mark[j][i] = -1;
      }
    }
  sort(b.begin(), b.end());
  lem1(n);
  lem2(k);
  while (m--) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    int x1 = v % n, x2 = u % n, y1 = v / n, y2 = u / n;
    if (a[x1][y1] == 'X' || a[x2][y2] == 'X' || mark[x1][y1] != mark[x2][y2]) {
      cout << -1 << endl;
      continue;
    }
    if (x1 == x2 && y1 == y2) {
      cout << 0 << endl;
      continue;
    }
    if (x1 == x2) {
      cout << 1 << endl;
      continue;
    }
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (b.size() == 0) {
      cout << x2 - x1 + abs(y2 - y1) << endl;
      continue;
    }
    int ii = bs(x1, k), jj = bs(x2, k);
    int ans = Dif(ii, jj - 1);
    if (ans == 0) {
      cout << x2 - x1 + abs(y2 - y1) << endl;
      continue;
    }
    if (y1 != b[ii].type) ans--;
    if (y2 == b[jj - 1].type) ans++;
    cout << x2 - x1 + ans << endl;
  }
  return 0;
}
