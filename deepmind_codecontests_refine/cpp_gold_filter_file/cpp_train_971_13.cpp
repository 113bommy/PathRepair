#include <bits/stdc++.h>
using namespace std;
int ABS(int a) {
  if (a < 0) return (-a);
  return a;
}
int main() {
  string s[2];
  int n, k;
  cin >> n >> k;
  cin >> s[0] >> s[1];
  bool vis[2][200005] = {0};
  bool ans = false;
  queue<pair<int, int> > q;
  queue<int> dq;
  q.push(pair<int, int>(0, 0));
  dq.push(0);
  vis[0][0] = true;
  while (!q.empty()) {
    pair<int, int> x = q.front();
    int depth = dq.front();
    q.pop();
    dq.pop();
    bool wall = x.first;
    int idx = x.second;
    if (idx + k > n) {
      ans = true;
      break;
    }
    if (!vis[wall][idx + 1]) {
      if (idx + 1 >= depth + 1) {
        if (idx + 1 < n && s[wall][idx + 1] == 'X')
          ;
        else {
          q.push(pair<int, int>(wall, idx + 1));
          dq.push(depth + 1);
          vis[wall][idx + 1] = true;
        }
      }
    }
    if (idx - 1 > 0 && !vis[wall][idx - 1]) {
      if (idx - 1 >= depth + 1) {
        if (idx - 1 >= 0 && s[wall][idx - 1] == 'X')
          ;
        else {
          q.push(pair<int, int>(wall, idx - 1));
          dq.push(depth + 1);
          vis[wall][idx - 1] = true;
        }
      }
    }
    if (!vis[!wall][idx + k]) {
      if (idx + k >= depth + 1) {
        if (idx + k < n && s[!wall][idx + k] == 'X')
          ;
        else {
          q.push(pair<int, int>(!wall, idx + k));
          dq.push(depth + 1);
          vis[!wall][idx + k] = true;
        }
      }
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
