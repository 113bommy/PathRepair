#include <bits/stdc++.h>
using namespace std;
int RIGHT = 0;
int DOWN = 1;
int LEFT = 2;
int UP = 3;
int res_mat[4][4] = {{0, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
int get_dir(pair<int, int> curr, pair<int, int> next) {
  int curr_dir;
  if (curr.first < next.first) {
    curr_dir = RIGHT;
  }
  if (curr.second > next.second) {
    curr_dir = DOWN;
  }
  if (curr.first > next.first) {
    curr_dir = LEFT;
  }
  if (curr.second < next.second) {
    curr_dir = UP;
  }
  return curr_dir;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(a, b);
  }
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    pair<int, int> curr = v[i];
    pair<int, int> next = v[(i + 1) % n];
    pair<int, int> nextnext = v[(i + 2) % n];
    int dir1 = get_dir(curr, next);
    int dir2 = get_dir(next, nextnext);
    int add = res_mat[dir1][dir2];
    res += res_mat[dir1][dir2];
  }
  cout << res << endl;
  return 0;
}
