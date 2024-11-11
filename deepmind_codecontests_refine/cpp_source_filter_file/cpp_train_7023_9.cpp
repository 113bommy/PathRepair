#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > range, tmp;
string mat[2000];
int check(int c, pair<int, int> R) {
  int l, r;
  l = R.first;
  r = R.second;
  for (int i = l + 1; i <= r; i++) {
    if (mat[i][c] < mat[i - 1][c]) return 0;
  }
  int a, b;
  a = l;
  while (b <= r) {
    while (mat[a][c] == mat[b][c] && b <= r) {
      b++;
    }
    if (a != b - 1) tmp.push_back(make_pair(a, b - 1));
    a = b;
  }
  return 1;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    cin >> mat[i];
  }
  range.push_back(make_pair(1, n));
  int res = 0;
  for (int i = 0; i < m; i++) {
    int flag = 0;
    tmp.clear();
    for (int k = 0; k < range.size(); k++) {
      pair<int, int> R = range[k];
      if (!check(i, R)) {
        res++;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      range = tmp;
    }
  }
  cout << res << endl;
}
