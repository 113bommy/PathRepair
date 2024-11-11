#include <bits/stdc++.h>
using namespace std;
queue<tuple<int, int, int>> q;
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
  int i, j, val = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      stand_by[i][j] = LLONG_MAX;
      if (j > 0 && in[i][j] == in[i][j - 1]) {
        q.push(tie(i, j, val));
      } else if (j < m - 1 && in[i][j] == in[i][j + 1]) {
        q.push(tie(i, j, val));
      } else if (i > 0 && in[i][j] == in[i - 1][j]) {
        q.push(tie(i, j, val));
      } else if (i < n - 1 && in[i][j] == in[i + 1][j]) {
        q.push(tie(i, j, val));
      }
    }
  }
  while (!q.empty()) {
    tie(i, j, val) = q.front();
    q.pop();
    if (stand_by[i][j] == LLONG_MAX) {
      stand_by[i][j] = (long long int)val;
      val += 1;
      if (j > 0) {
        q.push(make_tuple(i, j - 1, val));
      }
      if (j < m - 1) {
        q.push(make_tuple(i, j + 1, val));
      }
      if (i > 0) {
        q.push(make_tuple(i - 1, j, val));
      }
      if (i < n - 1) {
        q.push(make_tuple(i + 1, j, val));
      }
    }
  }
  long long int p, ans;
  while (Q--) {
    cin >> i >> j >> p;
    i--;
    j--;
    ans = (p - stand_by[i][j]);
    if (ans > 0) {
      cout << (ans + (long long int)in[i][j] - (long long int)'0') % 2 << endl;
    } else {
      cout << in[i][j] << endl;
    }
  }
}
