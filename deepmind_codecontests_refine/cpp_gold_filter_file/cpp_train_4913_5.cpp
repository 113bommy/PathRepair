#include <bits/stdc++.h>
using namespace std;
int n;
int a[1011];
vector<vector<int> > v, nxt_v;
vector<int> emp;
int todo[1011];
char ans[1011][1011];
vector<int> mk(int id, int st, int len) {
  vector<int> item(0);
  for (int i = 0; i < len; i++) item.push_back(v[id][st + i]);
  return item;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    puts("1\n1");
    return 0;
  }
  v.clear();
  vector<int> item(0);
  for (int i = 0; i <= n; i++) item.push_back(i);
  v.push_back(item);
  emp.clear();
  for (int i = 0; i < n; i++) {
    int sz = (int)v.size();
    int cnt1 = (sz > 0) ? max(1, a[i] - (int)emp.size()) : 0;
    if (cnt1 <= sz) {
      for (int j = 0; j < sz; j++) todo[j] = (j < cnt1) ? 1 : 0;
    } else if (n + 1 - (int)emp.size() - cnt1 <= sz) {
      for (int j = 0; j < sz; j++)
        todo[j] =
            (int)v[j].size() - ((j < n + 1 - (int)emp.size() - cnt1) ? 1 : 0);
    } else {
      int rem = cnt1 - sz;
      for (int j = 0; j < sz; j++) {
        int x = min(rem, (int)v[j].size() - 1);
        rem -= x;
        todo[j] = 1 + x;
      }
    }
    for (int j = 0; j < sz; j++) {
      for (int k = 0; k < todo[j]; k++) ans[v[j][k]][i] = '1';
      for (int k = todo[j]; k < (int)v[j].size(); k++) ans[v[j][k]][i] = '0';
    }
    for (int j = 0; j < (int)emp.size(); j++)
      ans[emp[j]][i] = (j < (a[i] - cnt1)) ? '1' : '0';
    nxt_v.clear();
    for (int j = 0; j < sz; j++) {
      if (todo[j] > 1)
        nxt_v.push_back(mk(j, 0, todo[j]));
      else if (todo[j] == 1)
        emp.push_back(v[j][0]);
      if (todo[j] < (int)v[j].size() - 1)
        nxt_v.push_back(mk(j, todo[j], (int)v[j].size() - todo[j]));
      else if (todo[j] == (int)v[j].size() - 1)
        emp.push_back(v[j].back());
    }
    v = nxt_v;
  }
  printf("%d\n", n + 1);
  for (int i = 0; i <= n; i++) {
    ans[i][n] = 0;
    printf("%s\n", ans[i]);
  }
  return 0;
}
