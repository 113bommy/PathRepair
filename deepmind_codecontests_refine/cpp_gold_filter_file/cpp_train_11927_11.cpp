#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2100;
long long t[MAX_N][MAX_N];
void update(int x, int y, int delta, int n, int m) {
  for (int i = x; i < n; i = ((i + 1) | i))
    for (int j = y; j < m; j = ((j + 1) | j)) t[i][j] += delta;
}
void update_(int x, int y, int delta, int n, int m) {
  for (int i = x; i < n; i = ((i + 1) | i))
    for (int j = y; j < m; j = ((j + 1) | j)) t[i][j] -= delta;
}
long long sum(int x, int y) {
  long long ans = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1) ans += t[i][j];
  return ans;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int len[k];
  vector<vector<int> > arr_x(k), arr_y(k), arr_w(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &len[i]);
    for (int j = 0; j < len[i]; ++j) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      arr_x[i].push_back(x - 1);
      arr_y[i].push_back(y - 1);
      arr_w[i].push_back(w);
    }
  }
  vector<bool> used(k, true);
  vector<int> operation(k, 0);
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < arr_x[i].size(); ++j)
      update(arr_x[i][j], arr_y[i][j], arr_w[i][j], n, m);
  int q;
  scanf("%d", &q);
  for (int j = 0; j < q; ++j) {
    string s;
    cin >> s;
    if (s == "SWITCH") {
      int num;
      scanf("%d", &num);
      --num;
      operation[num] ^= 1;
    } else {
      for (int j = 0; j < k; ++j)
        if (operation[j]) {
          int num = j;
          if (used[j]) {
            for (int i = 0; i < arr_x[num].size(); ++i)
              update_(arr_x[num][i], arr_y[num][i], arr_w[num][i], n, m);
            used[j] = false;
          } else {
            for (int i = 0; i < arr_x[num].size(); ++i)
              update(arr_x[num][i], arr_y[num][i], arr_w[num][i], n, m);
            used[j] = true;
          }
          operation[j] = 0;
        }
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      --x1;
      --y1;
      --x2;
      --y2;
      long long res = (sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) -
                       sum(x1 - 1, y2));
      printf("%I64d\n", res);
    }
  }
  return 0;
}
