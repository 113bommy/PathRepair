#include <bits/stdc++.h>
using namespace std;
int n, m;
int b[10008];
struct data {
  int val;
  string name;
  data() {}
  data(string a, int c) {
    name = a;
    val = c;
  }
};
vector<data> ans[10007];
bool cmp(data a, data b) { return a.val < b.val; }
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) {
      string a;
      int b, c;
      cin >> a >> b >> c;
      ans[b].push_back(data(a, c));
    }
    for (int i = 1; i <= m; i++) {
      sort(ans[i].begin(), ans[i].end(), cmp);
    }
    for (int i = 1; i <= m; i++) {
      int p = ans[i].size();
      if (ans[i].size() == 2) {
        cout << ans[i][0].name << " " << ans[i][1].name << endl;
      } else if (ans[i][p - 3].val == ans[i][p - 2].val) {
        puts("?");
      } else {
        cout << ans[i][p - 1].name << " " << ans[i][p - 2].name << endl;
      }
    }
  }
  return 0;
}
