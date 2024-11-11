#include <bits/stdc++.h>
using namespace std;
const int N = 150000;
int n, m;
string M[N], A[N];
char p[4] = {'A', 'C', 'G', 'T'};
int v(bool save = false) {
  int res = 0;
  for (int j = 0; j < m; j++) {
    int bx = 0, bs = 3 * N;
    for (int x = 0; x < 2; x++) {
      int s = 0;
      for (int i = 0; i < n; i++) {
        s += M[i][j] != p[((i + x) % 2) + 2 * (j % 2)] ? 1 : 0;
      }
      if (s < bs) {
        bx = x;
        bx = s;
      }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += M[i][j] != p[((i + bx) % 2) + 2 * (j % 2)] ? 1 : 0;
      if (save) A[i][j] = p[((i + bx) % 2) + 2 * (j % 2)];
    }
    res += s;
  }
  return res;
}
int h(bool save = false) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int bx = 0, bs = 3 * N;
    for (int x = 0; x < 2; x++) {
      int s = 0;
      for (int j = 0; j < m; j++) {
        s += M[i][j] != p[2 * (i % 2) + ((j + x) % 2)] ? 1 : 0;
      }
      if (s < bs) {
        bx = x;
        bx = s;
      }
    }
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += M[i][j] != p[2 * (i % 2) + ((j + bx) % 2)] ? 1 : 0;
      if (save) A[i][j] = p[2 * (i % 2) + ((j + bx) % 2)];
    }
    res += s;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> M[i];
    A[i] = M[i];
  }
  int ans = 3 * N;
  do {
    if (ans > v()) {
      ans = v();
      v(true);
    }
    if (ans > h()) {
      ans = h();
      h(true);
    }
  } while (next_permutation(p, p + 4));
  for (int i = 0; i < n; i++) cout << A[i] << endl;
  return 0;
}
