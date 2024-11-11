#include <bits/stdc++.h>
using namespace std;
int n, m, k, dir, a, b, stx, sty;
string str;
set<pair<int, int> > A[204800], B[204800];
map<int, bool> arr[204800];
bool flag;
void init() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    do {
      A[a - (b) + m + 1].insert(make_pair(a, b));
      B[a + b].insert(make_pair(a, b));
      arr[a][b] = true;
    } while (0);
  }
  for (int i = 0; i <= m + 1; i++) {
    do {
      A[0 - (i) + m + 1].insert(make_pair(0, i));
      B[0 + i].insert(make_pair(0, i));
      arr[0][i] = true;
    } while (0);
    do {
      A[n + 1 - (i) + m + 1].insert(make_pair(n + 1, i));
      B[n + 1 + i].insert(make_pair(n + 1, i));
      arr[n + 1][i] = true;
    } while (0);
  }
  for (int i = 0; i <= n + 1; i++) {
    do {
      A[i - (0) + m + 1].insert(make_pair(i, 0));
      B[i + 0].insert(make_pair(i, 0));
      arr[i][0] = true;
    } while (0);
    do {
      A[i - (m + 1) + m + 1].insert(make_pair(i, m + 1));
      B[i + m + 1].insert(make_pair(i, m + 1));
      arr[i][m + 1] = true;
    } while (0);
  }
  cin >> stx >> sty >> str;
  dir = (str[1] == 'E') | ((str[0] == 'S') << 1);
}
void calc(int nx, int ny, int ndir, int &x, int &y, int &d, int &nxt_x,
          int &nxt_y) {
  switch (ndir) {
    case 0: {
      auto p = A[nx - ny + m + 1].lower_bound(make_pair(nx, ny));
      p--;
      nxt_x = p->first;
      nxt_y = p->second;
      a = arr[nxt_x + 1].count(nxt_y);
      b = arr[nxt_x].count(nxt_y + 1);
      if (!a && b) {
        x = nxt_x + 1;
        y = nxt_y;
        d = 2;
      } else if (a && !b) {
        x = nxt_x;
        y = nxt_y + 1;
        d = 1;
      } else {
        x = nxt_x + 1;
        y = nxt_y + 1;
        d = 3;
      }
      break;
    }
    case 1: {
      auto p = B[nx + ny].lower_bound(make_pair(nx, ny));
      p--;
      nxt_x = p->first;
      nxt_y = p->second;
      a = arr[nxt_x + 1].count(nxt_y);
      b = arr[nxt_x].count(nxt_y - 1);
      if (!a && b) {
        x = nxt_x + 1;
        y = nxt_y;
        d = 3;
      } else if (a && !b) {
        x = nxt_x;
        y = nxt_y - 1;
        d = 0;
      } else {
        x = nxt_x + 1;
        y = nxt_y - 1;
        d = 2;
      }
      break;
    }
    case 2: {
      auto p = B[nx + ny].upper_bound(make_pair(nx, ny));
      nxt_x = p->first;
      nxt_y = p->second;
      a = arr[nxt_x - 1].count(nxt_y);
      b = arr[nxt_x].count(nxt_y + 1);
      if (!a && b) {
        x = nxt_x - 1;
        y = nxt_y;
        d = 0;
      } else if (a && !b) {
        x = nxt_x;
        y = nxt_y + 1;
        d = 3;
      } else {
        x = nxt_x - 1;
        y = nxt_y + 1;
        d = 1;
      }
      break;
    }
    default: {
      auto p = A[nx - ny + m + 1].upper_bound(make_pair(nx, ny));
      nxt_x = p->first;
      nxt_y = p->second;
      a = arr[nxt_x - 1].count(nxt_y);
      b = arr[nxt_x].count(nxt_y - 1);
      if (!a && b) {
        x = nxt_x - 1;
        y = nxt_y;
        d = 1;
      } else if (a && !b) {
        x = nxt_x;
        y = nxt_y - 1;
        d = 2;
      } else {
        x = nxt_x - 1;
        y = nxt_y - 1;
        d = 0;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  init();
  int ans = 0;
  int tmp_x, tmp_y, tmp_dir, nxt_x, nxt_y;
  calc(stx, sty, dir, stx, sty, dir, nxt_x, nxt_y);
  for (int x = stx, y = sty, d = dir;; x = tmp_x, y = tmp_y, d = tmp_dir) {
    calc(x, y, d, tmp_x, tmp_y, tmp_dir, nxt_x, nxt_y);
    ans += abs(x - nxt_x);
    if (tmp_x == stx && tmp_y == sty && tmp_dir == dir) {
      break;
    }
    if (tmp_dir + d == 3) {
      flag = true;
    }
  }
  ans >>= flag;
  cout << ans << endl;
  return 0;
}
