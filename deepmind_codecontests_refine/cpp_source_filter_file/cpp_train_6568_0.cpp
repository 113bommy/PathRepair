#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
bool black[MAX];
vector<int> vec[MAX];
bool old_black[MAX];
const int MAX_BLOCK_SIZE = 600;
int t[MAX], v[MAX];
bool used[MAX];
vector<pair<pair<int, int>, int>> v2[MAX];
int push[MAX];
bool clear[MAX];
void dfs_1(int pos, int prev = -1, int white = 0, int dist = 0) {
  if (used[pos]) {
    if (prev != -1) v2[prev].push_back(make_pair(make_pair(pos, white), dist));
    for (int a : vec[pos]) dfs_1(a, pos, 0, 0);
  } else {
    if (!black[pos]) white++;
    for (int a : vec[pos]) dfs_1(a, prev, white, dist + 1);
  }
}
void make_1(int pos) {
  if (!black[pos]) {
    black[pos] = true;
    return;
  }
  push[pos]++;
  for (auto a : v2[pos])
    if (a.first.second + 1 <= push[pos]) make_1(a.first.first);
}
void make_2(int pos) {
  black[pos] = false;
  push[pos] = 0;
  clear[pos] = true;
  for (auto &a : v2[pos]) {
    a.first.second = a.second;
    make_2(a.first.first);
  }
}
void dfs_2(int pos, int p = 0, bool cl = false) {
  if (used[pos]) {
    p = push[pos];
    cl |= clear[pos];
  } else {
    black[pos] = old_black[pos];
    if (cl) black[pos] = false;
    if (!black[pos] && p) {
      black[pos] = true;
      p--;
    }
  }
  for (int a : vec[pos]) dfs_2(a, p, cl);
}
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    vec[a].push_back(i);
  }
  for (int i = 1; i <= q; i++) cin >> t[i] >> v[i];
  int root = 1;
  for (int i = 1; i <= 1; i += MAX_BLOCK_SIZE) {
    for (int j = 1; j <= n; j++) {
      used[j] = false;
      v2[j].clear();
      old_black[j] = black[j];
      push[j] = 0;
      clear[j] = false;
    }
    for (int j = 0; j < MAX_BLOCK_SIZE && i + j <= q; j++)
      used[v[i + j]] = true;
    dfs_1(root);
    for (int j = 0; j < MAX_BLOCK_SIZE && i + j <= q; j++) {
      int t = ::t[i + j];
      int v = ::v[i + j];
      if (t == 1)
        make_1(v);
      else if (t == 2)
        make_2(v);
      else
        cout << (black[v] ? "black" : "white") << endl;
    }
    dfs_2(root);
  }
}
