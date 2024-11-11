#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> mat, res;
int row(int r, char a, char b) {
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans += (mat[r][i] != (i % 2 ? b : a));
  }
  return ans;
}
int col(int c, char a, char b) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (mat[i][c] != (i % 2 ? b : a));
  }
  return ans;
}
void fillr(int r, char a, char b) {
  for (int i = 0; i < m; i++) {
    res[r][i] = (i % 2 ? b : a);
  }
}
void fillc(int c, int a, int b) {
  for (int i = 0; i < n; i++) {
    res[i][c] = (i % 2 ? b : a);
  }
}
int main() {
  cin >> n >> m;
  mat = vector<string>(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  res = mat;
  vector<char> vec{'A', 'C', 'G', 'T'};
  int ans = 2e9;
  bool r;
  vector<char> fin;
  do {
    int here = 0;
    for (int i = 0; i < n; i++) {
      here += min(row(i, vec[2 - 2 * (i & 1)], vec[3 - 2 * (i & 1)]),
                  row(i, vec[3 - 2 * (i & 1)], vec[2 - 2 * (i & 1)]));
    }
    if (here < ans) {
      ans = here;
      fin = vec;
      r = 1;
    }
    here = 0;
    for (int j = 0; j < m; j++) {
      here += min(col(j, vec[2 - 2 * (j & 1)], vec[3 - 2 * (j & 1)]),
                  col(j, vec[3 - 2 * (j & 1)], vec[2 - 2 * (j & 1)]));
    }
    if (here < ans) {
      ans = here;
      fin = vec;
      r = 0;
    }
  } while (next_permutation(vec.begin(), vec.end()));
  if (r) {
    for (int i = 0; i < n; i++) {
      if (row(i, fin[2 - 2 * (i & 1)], fin[3 - 2 * (i & 1)]) <
          row(i, fin[3 - 2 * (i & 1)], fin[2 - 2 * (i & 1)])) {
        fillr(i, fin[2 - 2 * (i & 1)], fin[3 - 2 * (i & 1)]);
      } else {
        fillr(i, fin[3 - 2 * (i & 1)], fin[2 - 2 * (i & 1)]);
      }
    }
  } else {
    for (int j = 0; j < m; j++) {
      if (j, col(j, fin[2 - 2 * (j & 1)], fin[3 - 2 * (j & 1)]) < j,
          col(j, fin[3 - 2 * (j & 1)], fin[2 - 2 * (j & 1)])) {
        fillc(j, fin[2 - 2 * (j & 1)], fin[3 - 2 * (j & 1)]);
      } else {
        fillc(j, fin[3 - 2 * (j & 1)], fin[2 - 2 * (j & 1)]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << endl;
  }
  return 0;
}
