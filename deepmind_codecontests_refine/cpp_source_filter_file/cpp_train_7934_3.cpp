#include <bits/stdc++.h>
using namespace std;
int const N = 8;
char maze[N + 2][N + 2];
int main() {
  while (scanf("%s", maze[1] + 1) == 1) {
    for (int n_ = (7), i = 0; i < n_; ++i) scanf("%s", maze[2 + i] + 1);
    for (int n_ = (N + 2), i = 0; i < n_; ++i)
      for (int n_ = (N + 2), j = 0; j < n_; ++j)
        if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
          maze[i][j] = 0;
        }
    maze[N][1] = '.';
    vector<pair<int, int> > P, Q;
    Q.push_back(pair<int, int>(N, 1));
    bool win;
    for (int step = 0;; ++step) {
      if (step % 2 == 0) {
        map<pair<int, int>, bool> mk;
        for (int n_ = (Q.size()), iq = 0; iq < n_; ++iq) {
          pair<int, int> curr = Q[iq];
          int i = curr.first;
          int j = curr.second;
          for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy < 1; dy++) {
              if (maze[i + dx][j + dy] == '.') {
                pair<int, int> nxt(i + dx, j + dy);
                if (!mk[nxt]) {
                  P.push_back(nxt);
                  mk[nxt] = true;
                }
              }
            }
          }
        }
      } else {
        bool has = false;
        for (int i = N; i >= 1; --i) {
          for (int j = 1; j <= N; ++j) {
            if (maze[i][j] == 'S') {
              maze[i + 1][j] = 'S';
              maze[i][j] = '.';
              has = true;
            }
          }
        }
        if (!has) {
          win = true;
          break;
        }
        for (int n_ = (Q.size()), iq = 0; iq < n_; ++iq) {
          pair<int, int> curr = Q[iq];
          int i = curr.first;
          int j = curr.second;
          if (maze[i][j] != 'S') {
            P.push_back(curr);
          }
        }
        if (!P.size()) {
          win = false;
          break;
        }
      }
      P.swap(Q);
      P.clear();
    }
    puts(win ? "WIN" : "LOSE");
  }
  return 0;
}
