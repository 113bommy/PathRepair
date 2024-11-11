#include <bits/stdc++.h>
using namespace std;
struct timer {
  time_t start;
  timer() { start = clock(); }
  ~timer() {
    cerr << 1. * (clock() - start) / CLOCKS_PER_SEC << " secs" << endl;
  }
};
int n, m, a[30];
int ok[30][30][30];
bool visit[24][1 << 23];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 1; i < (n); i++) {
    for (int j = 0; j < (i); j++)
      for (int k = j; k < (i); k++) {
        if (a[j] + a[k] == a[i]) ok[i][j][k] = ok[i][k][j] = 1;
      }
  }
  int lo = 1, hi = n + 1;
  while (lo + 1 < hi) {
    int mi = (lo + hi) / 2;
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int> > Q;
    Q.push(pair<int, int>(0, 1));
    pair<int, int> p;
    int success = 0;
    int nmask;
    while (!Q.empty()) {
      p = Q.front();
      Q.pop();
      if (p.first == n - 1) {
        success = 1;
        break;
      }
      visit[p.first][p.second] = 1;
      if (p.first < mi - 1) {
        for (int i = 0; i < (n); i++)
          for (int j = 0; j < (n); j++)
            if ((p.second >> i & 1) && (p.second >> j & 1) &&
                ok[p.first + 1][i][j]) {
              Q.push(make_pair(p.first + 1, p.second | 1 << p.first + 1));
              goto end;
            }
      end:;
      } else {
        for (int i = 0; i < (n); i++)
          for (int j = 0; j < (n); j++)
            if ((p.second >> i & 1) && (p.second >> j & 1) &&
                ok[p.first + 1][i][j]) {
              for (int k = 0; k < (n); k++)
                if (p.second >> k & 1) {
                  if (!visit[p.first + 1]
                            [p.second ^ (1 << k) | (1 << p.first + 1)]) {
                    visit[p.first + 1]
                         [p.second ^ (1 << k) | (1 << p.first + 1)] = 1;
                    Q.push(make_pair(p.first + 1,
                                     p.second ^ (1 << k) | (1 << p.first + 1)));
                  }
                }
              goto end2;
            }
      end2:;
      }
    }
    if (success)
      hi = mi;
    else
      lo = mi;
  }
  cout << (hi <= n ? hi : -1);
}
