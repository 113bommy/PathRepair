#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 7;
const long long maxe = 1e6 + 7;
const long long INF = 1e9 + 7;
const double PI = acos(-1);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
inline void Max(int &a, int b) {
  if (b > a) a = b;
}
inline void Min(int &a, int b) {
  if (a == -1 || b < a) a = b;
}
int n, m;
int cnt[30];
int a[30][30];
bool run(int a[], int row, int l, int r) {
  if (a[l] == l && a[r] == r) {
    if (cnt[row] == 0) return true;
  } else if (a[r] == l && a[l] == r) {
    if (cnt[row] == 4 || cnt[row] == 2) return true;
  } else if (a[l] == r || a[r] == l) {
    if (cnt[row] == 3) return true;
  }
  return false;
}
bool solve(int l, int r) {
  for (int i = 1; i <= n; i++) {
    if (!run(a[i], i, l, r)) return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (j != a[i][j]) cnt[i]++;
    }
    if (cnt[i] != 0 && cnt[i] != 2) ans = false;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (solve(i, j)) ans = true;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
