#include <bits/stdc++.h>
using namespace std;
const int MN = 5000 + 100;
bool mark[MN];
int col[MN];
int coord[MN][2];
int n;
int dist(int a, int b) {
  return abs(coord[a][0] - coord[b][0]) + abs(coord[a][1] - coord[b][1]);
}
bool dfs(int v, int c, int t) {
  mark[v] = true;
  col[v] = c;
  bool ans = true;
  for (int i = 0; i < n; i++) {
    if (!mark[i] && dist(v, i) > t) {
      ans &= dfs(i, 1 - c, t);
    } else if (mark[i] && col[i] == col[v] && dist(v, i) > t && i != v) {
      ans = false;
      ;
    }
  }
  return ans;
}
int bs() {
  int lo = -1, hi = 6000;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    memset(mark, 0, sizeof mark);
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (!mark[i]) {
        ans &= dfs(i, 0, mid);
      }
    }
    if (ans) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return hi;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> coord[i][0] >> coord[i][1];
  }
  int t = bs();
  cout << t << endl;
  memset(mark, 0, sizeof mark);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      dfs(i, 0, t);
      ans++;
    }
  }
  int ans1 = 1;
  for (int i = 0; i < ans; i++) {
    ans1 = (2ll * ans1) % (1000 * 1000 * 1000 + 7);
  }
  cout << ans1;
}
