#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
int to[220];
int from[220];
bool state[220];
bool ok[220];
bool need[220];
bool vis[220];
vector<pair<int, int> > seq;
int Search() {
  for (int i = 1;; i++)
    if (!state[i] && !vis[i]) return i;
}
void move(int x, int y) {
  state[x] = 0;
  state[y] = 1;
  seq.push_back(make_pair(x, y));
}
int solve(bool f, int x) {
  if (f && vis[x]) return false;
  vis[x] = 1;
  if (to[x] == x || !to[x]) {
    ok[x] = 1;
    vis[x] = 0;
    return true;
  }
  if (!state[to[x]]) {
    seq.push_back(make_pair(x, to[x]));
    state[to[x]] = 1;
    state[x] = 0;
    ok[x] = 1;
    vis[x] = 0;
    return true;
  }
  if (solve(1, to[x])) {
    if (!ok[x]) move(x, to[x]);
  } else {
    int emp = Search();
    move(x, emp);
    solve(0, to[x]);
    move(emp, to[x]);
  }
  ok[x] = 1;
  vis[x] = 0;
  return true;
}
int main() {
  int m, n;
  cin >> m >> n;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y;
      to[y] = cnt++;
      from[to[y]] = y;
      state[y] = 1;
      need[y] = 1;
    }
  }
  for (int i = 1; i <= m; i++)
    if (need[i] && (!ok[i])) solve(1, i);
  cout << (int)(seq.size()) << endl;
  for (int i = 0; i < (int)(seq.size()); i++)
    cout << seq[i].first << " " << seq[i].second << endl;
  return 0;
}
