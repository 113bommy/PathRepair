#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    string s;
    cin >> s;
    if (n <= 2) {
      cout << "Draw\n";
      continue;
    }
    bool win = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] != 'W') {
        continue;
      }
      if ((int)(g[i]).size() >= 3) {
        win = true;
        break;
      }
      if ((int)(g[i]).size() == 2 && n >= 4) {
        win = true;
        break;
      }
      int to = g[i][0];
      if ((int)(g[to]).size() >= 3) {
        win = true;
        break;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        ++cnt;
      }
    }
    if (n == 3 && cnt >= 2) {
      win = true;
    }
    if (win) {
      cout << "White\n";
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if ((int)(g[i]).size() >= 4) {
        win = true;
        break;
      }
      if ((int)(g[i]).size() == 3) {
        int nonleaves = 0;
        for (int to : g[i]) {
          if ((int)(g[to]).size() >= 2) {
            ++nonleaves;
          }
        }
        if (nonleaves >= 2) {
          win = true;
          break;
        }
      }
    }
    int cnt3 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      if ((int)(g[i]).size() == 3) {
        ++cnt3;
      } else if ((int)(g[i]).size() == 2) {
        ++cnt2;
      }
    }
    if (cnt3 == 2 && n % 2 == 1) {
      win = true;
    }
    if (cnt3 == 1 && cnt && n % 2 == 0) {
      win = true;
    }
    if (cnt3 == 0 && cnt >= 2 && n % 2 == 1) {
      win = true;
    }
    cout << (win ? "White\n" : "Draw\n");
  }
}
