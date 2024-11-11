#include <bits/stdc++.h>
using namespace std;
void mxe(int &a, int b) {
  if (b > a) a = b;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> div(n + 1);
  vector<vector<int>> num(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      div[j].push_back(i);
      num[i].push_back(j);
    }
  }
  vector<int> max_div(n + 1, -1);
  vector<bool> u(n + 1);
  vector<int> ans = {-1};
  int cur_num = 0;
  for (int d = 1; d <= n; d++) {
    for (int x : num[d]) {
      if (u[x] || max_div[x] > d) continue;
      u[x] = true;
      cur_num++;
      for (int i = (int)div[x].size() - 1; div[x][i] > d; i--) {
        int dd = div[x][i];
        for (int xx : num[dd]) {
          mxe(max_div[xx], dd);
        }
      }
    }
    while ((int)ans.size() <= cur_num) ans.push_back(d);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
