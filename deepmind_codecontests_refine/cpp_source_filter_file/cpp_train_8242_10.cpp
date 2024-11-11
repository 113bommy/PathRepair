#include <bits/stdc++.h>
using namespace std;
vector<int> rb[100002], cb[100002];
long long n, m, k;
long long ur = 0, dr, lc = 0, rc;
void printVector(vector<int> x) {
  for (int xx : x) cout << xx << " ";
  cout << "\n";
}
long long solve(long long x, long long y, int dir) {
  long long ans = 0;
  while (true) {
    if (dir == 2) rc = min(rc, y);
    if (dir == 3) dr = min(dr, x);
    if (dir == 4) lc = max(lc, y);
    if (dir == 1) ur = max(ur, x);
    if (dir == 1) {
      long long nextBlockCol =
          lower_bound(rb[x].begin(), rb[x].end(), y) - rb[x].begin();
      nextBlockCol = rb[x][nextBlockCol];
      nextBlockCol = min(nextBlockCol, rc);
      if (nextBlockCol - 1 == y) return ans;
      ans += nextBlockCol - y - 1;
      x = x;
      y = nextBlockCol - 1;
      dir = 2;
    } else if (dir == 2) {
      long long nextBlockRow =
          lower_bound(cb[y].begin(), cb[y].end(), x) - cb[y].begin();
      nextBlockRow = cb[y][nextBlockRow];
      nextBlockRow = min(nextBlockRow, dr);
      if (nextBlockRow - 1 == x) return ans;
      ans += nextBlockRow - x - 1;
      x = nextBlockRow - 1;
      y = y;
      dir = 3;
    } else if (dir == 3) {
      long long nextBlockCol =
          lower_bound(rb[x].begin(), rb[x].end(), y) - rb[x].begin() - 1;
      nextBlockCol = rb[x][nextBlockCol];
      nextBlockCol = max(nextBlockCol, lc);
      if (nextBlockCol + 1 == y) return ans;
      ans += y - nextBlockCol - 1;
      x = x;
      y = nextBlockCol + 1;
      dir = 4;
    } else {
      long long nextBlockRow =
          lower_bound(cb[y].begin(), cb[y].end(), x) - cb[y].begin() - 1;
      nextBlockRow = cb[y][nextBlockRow];
      nextBlockRow = max(nextBlockRow, ur);
      if (nextBlockRow + 1 == x) return ans;
      ans += x - nextBlockRow - 1;
      x = nextBlockRow + 1;
      y = y;
      dir = 1;
    }
  }
}
bool handleLinear() {
  long long marked = 0;
  for (int i = 1; i <= m; i++) {
    auto it = lower_bound(cb[1].begin(), cb[1].end(), i);
    if (it != cb[1].end() && *it == i)
      break;
    else
      marked++;
  }
  return marked == n * m - k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  dr = n + 1;
  rc = m + 1;
  for (int i = 1; i <= k; i++) {
    int r, c;
    cin >> r >> c;
    cb[c].push_back(r);
    rb[r].push_back(c);
  }
  for (int i = 0; i <= m; i++) {
    cb[i].push_back(0);
    cb[i].push_back(n + 1);
  }
  for (int i = 0; i <= n; i++) {
    rb[i].push_back(0);
    rb[i].push_back(m + 1);
  }
  for (int i = 0; i <= n + 1; i++) sort(rb[i].begin(), rb[i].end());
  for (int i = 0; i <= m + 1; i++) sort(cb[i].begin(), cb[i].end());
  if (handleLinear()) {
    cout << "Yes\n";
    return 0;
  }
  long long marked = 1 + solve(1, 1, 1);
  if (marked == n * m - k) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
