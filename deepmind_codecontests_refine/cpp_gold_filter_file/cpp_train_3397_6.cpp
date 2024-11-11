#include <bits/stdc++.h>
using namespace std;
struct point {
  int i, j;
};
char A[30][30];
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<point> shift;
  point c;
  double mini[26];
  double dis;
  for (int i = 0; i < 26; ++i) {
    mini[i] = 1000000;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> (A[i][j]);
      if (A[i][j] == 'S') {
        c.i = i;
        c.j = j;
        shift.push_back(c);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mini[A[i][j] - 'a'] == 1000000) mini[A[i][j] - 'a'] = 100000;
      for (int k = 0; k < shift.size(); ++k) {
        dis = sqrt(abs(i - shift[k].i) * abs(i - shift[k].i) +
                   abs(j - shift[k].j) * abs(j - shift[k].j));
        if (dis < mini[A[i][j] - 'a']) {
          mini[A[i][j] - 'a'] = dis;
        }
      }
    }
  }
  int q, cnt = 0;
  bool shif = (shift.size());
  string T;
  cin >> q >> T;
  for (int i = 0; i < q; ++i) {
    if (T[i] > 'Z') {
      if (mini[T[i] - 'a'] == 1000000.0) {
        cout << -1;
        return 0;
      }
    } else {
      if (!shif || mini[T[i] - 'a' + 32] == 1000000.0) {
        cout << -1;
        return 0;
      } else {
        cnt += (mini[T[i] - 'a' + 32] > x);
      }
    }
  }
  cout << cnt;
}
