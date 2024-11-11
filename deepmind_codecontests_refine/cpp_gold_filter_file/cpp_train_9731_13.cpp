#include <bits/stdc++.h>
using namespace std;
vector<long int> a[100000 + 10];
vector<long int> b[100000 + 10];
vector<long int> c[100000 + 10];
vector<long int> bfs;
long long int dp[100000 + 10];
long long int mark[100000 + 10];
long long int n, m;
long long int INF = 999999999;
bool ans = true;
bool mark_ans_khfan[100000 + 10];
long long int mark_super[100000 + 10];
void inf() {
  for (int i = 0; i <= 100000 + 1; i++) dp[i] = INF;
}
void print_adg(int x) {
  if (ans) {
    for (int i = 0; i < a[x].size(); i++) {
      if (mark[a[x][i]] + 1 <= mark[x] && (dp[a[x][i]] + c[x][i]) == dp[x] &&
          ans) {
        if (ans) {
          mark_ans_khfan[a[x][i]] = 1;
        }
        if (a[x][i] == 1) ans = false;
        if (ans) print_adg(a[x][i]);
      }
    }
  } else
    return;
}
int main() {
  inf();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    if (w == 0)
      w = 1;
    else if (w == 1)
      w = 0;
    a[x].push_back(y);
    a[y].push_back(x);
    c[x].push_back(w);
    c[y].push_back(w);
    b[x].push_back(y);
  }
  int j = 0;
  bfs.push_back(1);
  mark[1] = 1;
  dp[1] = 0;
  while (j < bfs.size()) {
    int x = bfs[j];
    for (int i = 0; i < a[x].size(); i++) {
      if (mark[a[x][i]] == 0) {
        dp[a[x][i]] = dp[x] + c[x][i];
        mark[a[x][i]] = mark[x] + 1;
        bfs.push_back(a[x][i]);
      }
      if (mark[a[x][i]] != 0 && mark[x] + 1 <= mark[a[x][i]]) {
        if ((dp[x] + c[x][i]) <= dp[a[x][i]]) {
          dp[a[x][i]] = (dp[x] + c[x][i]);
        }
      }
    }
    j++;
  }
  mark_ans_khfan[n] = 1;
  print_adg(n);
  int super = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      if (mark_ans_khfan[i] == 1 && mark_ans_khfan[a[i][j]] == 1) {
        if (c[i][j] == 1) {
          super++;
        }
      } else {
        if (c[i][j] == 0) {
          super++;
        }
      }
    }
  }
  cout << super / 2 << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      if (mark_ans_khfan[i] == 1 && mark_ans_khfan[a[i][j]] == 1) {
        if (c[i][j] == 1 && mark_super[i] == 0 && mark_super[a[i][j]] == 0) {
          cout << i << " " << a[i][j] << " " << 1 << endl;
        }
      } else {
        if (c[i][j] == 0 && mark_super[i] == 0 && mark_super[a[i][j]] == 0) {
          cout << i << " " << a[i][j] << " " << 0 << endl;
        }
      }
    }
    mark_super[i] = 1;
  }
}
