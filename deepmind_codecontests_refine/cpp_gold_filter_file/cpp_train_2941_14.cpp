#include <bits/stdc++.h>
using namespace std;
queue<tuple<int, int>> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, Q;
  cin >> n >> m >> Q;
  long long int stand_by[1005][1005];
  string in[1005];
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      stand_by[i][j] = LLONG_MAX;
      if (j > 0 && in[i][j] == in[i][j - 1]) {
        stand_by[i][j] = 0;
        q.push(make_tuple(i, j));
      } else if (j < m - 1 && in[i][j] == in[i][j + 1]) {
        stand_by[i][j] = 0;
        q.push(make_tuple(i, j));
      } else if (i > 0 && in[i][j] == in[i - 1][j]) {
        stand_by[i][j] = 0;
        q.push(make_tuple(i, j));
      } else if (i < n - 1 && in[i][j] == in[i + 1][j]) {
        stand_by[i][j] = 0;
        q.push(make_tuple(i, j));
      }
    }
  }
  while (!q.empty()) {
    tie(i, j) = q.front();
    q.pop();
    if (j > 0 && stand_by[i][j - 1] == LLONG_MAX) {
      stand_by[i][j - 1] = stand_by[i][j] + 1;
      q.push(make_tuple(i, j - 1));
    }
    if (j < m - 1 && stand_by[i][j + 1] == LLONG_MAX) {
      stand_by[i][j + 1] = stand_by[i][j] + 1;
      q.push(make_tuple(i, j + 1));
    }
    if (i > 0 && stand_by[i - 1][j] == LLONG_MAX) {
      stand_by[i - 1][j] = stand_by[i][j] + 1;
      q.push(make_tuple(i - 1, j));
    }
    if (i < n - 1 && stand_by[i + 1][j] == LLONG_MAX) {
      stand_by[i + 1][j] = stand_by[i][j] + 1;
      q.push(make_tuple(i + 1, j));
    }
  }
  long long int p, ans;
  while (Q--) {
    cin >> i >> j >> p;
    i = i - 1;
    j = j - 1;
    ans = (p - stand_by[i][j]);
    if (ans < 0) {
      ans = 0;
    }
    if (in[i][j] == '1') {
      cout << (ans + 1) % 2 << endl;
    } else {
      cout << (ans) % 2 << endl;
    }
  }
}
