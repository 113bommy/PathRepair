#include <bits/stdc++.h>
using namespace std;
struct cww {
  cww() {
    if (1) {
      ios::sync_with_stdio(false);
      cin.tie(0);
    }
  }
} star;
template <typename T>
inline void chmin(T &l, T r) {
  l = min(l, r);
}
template <typename T>
inline void chmax(T &l, T r) {
  l = max(l, r);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
int main() {
  int n, a, b;
  cin >> n;
  vector<vector<int> > s(2);
  for (int i = (0); i < (2); i++) {
    int sz;
    cin >> sz;
    for (int j = (0); j < (sz); j++) {
      int k;
      cin >> k;
      s[i].push_back(k);
    }
  }
  vector<vector<int> > win(2, vector<int>(n - 1));
  for (int i = (0); i < (2); i++)
    for (auto &it : win[i]) it = -((int)s[i].size());
  queue<pair<int, int> > que;
  for (int i = (0); i < (2); i++)
    for (auto &it : s[i]) {
      win[i][n - it - 1] = 1;
      que.push(pair<int, int>(i, n - it - 1));
    }
  while (que.size()) {
    auto p = que.front();
    que.pop();
    int i = p.first;
    int o = 1 - i;
    int pos = p.second;
    if (win[i][pos] == 0) {
      for (auto &it : s[o]) {
        int nxt = (pos - it + n) % n;
        if (nxt == n - 1) continue;
        if (win[o][nxt] < 0) {
          win[o][nxt] = 1;
          que.push(pair<int, int>(o, nxt));
        }
      }
    } else {
      for (auto &it : s[o]) {
        int nxt = (pos - it + n) % n;
        if (nxt == n - 1) continue;
        if (win[o][nxt] < 0) {
          win[o][nxt]++;
          if (win[o][nxt] == 0) que.push(pair<int, int>(o, nxt));
        }
      }
    }
  }
  for (int id = (0); id < (2); id++) {
    for (int i = (0); i < (n - 1); i++) {
      if (win[id][i] == 1)
        cout << (!i) + " "
             << "Win";
      if (win[id][i] == 0)
        cout << (!i) + " "
             << "Lose";
      if (win[id][i] == -1)
        cout << (!i) + " "
             << "Loop";
    }
    cout << endl;
  }
  return 0;
}
