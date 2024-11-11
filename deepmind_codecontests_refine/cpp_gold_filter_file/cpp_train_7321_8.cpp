#include <bits/stdc++.h>
using namespace std;
struct Obj {
  int money, size, id;
  Obj(int m = 0, int s = 0, int i = 0) : money(m), size(s), id(i) {}
};
bool cmpSize(Obj a, Obj b) { return a.size < b.size; }
bool cmpMoney(Obj a, Obj b) { return a.money > b.money; }
vector<int> e[(100000 + 10)];
int _link[(100000 + 10)];
char tmpuse[(100000 + 10)];
bool can(int t) {
  if (tmpuse[t]) return false;
  tmpuse[t] = true;
  for (int i(0), _n(e[t].size()); i < _n; ++i) {
    int j = e[t][i];
    if (_link[j] == -1 || can(_link[j])) {
      _link[j] = t;
      return true;
    }
  }
  return false;
}
Obj sh[(100000 + 10)], bu[(100000 + 10)];
int n, m;
void solve() {
  memset((_link), -1, sizeof(_link));
  long long ans = 0LL;
  int cnt = 0;
  for (int i(0), _n(n); i < _n; ++i) {
    memset((tmpuse), false, sizeof(tmpuse));
    if (can(sh[i].id)) ans += sh[i].money, ++cnt;
  }
  printf("%I64d\n", ans);
  printf("%d\n", (cnt));
  for (int j(0), _n(m); j < _n; ++j) {
    if (_link[j] != -1) {
      printf("%d %d\n", j + 1, _link[j] + 1);
    }
  }
}
int main() {
  scanf("%d", &(n));
  for (int i(0), _n(n); i < _n; ++i)
    scanf("%d", &(sh[i].money)), scanf("%d", &(sh[i].size)), sh[i].id = i;
  scanf("%d", &(m));
  for (int j(0), _n(m); j < _n; ++j)
    scanf("%d", &(bu[j].money)), scanf("%d", &(bu[j].size)), bu[j].id = j;
  sort(sh, sh + n, cmpSize);
  for (int j(0), _n(m); j < _n; ++j) {
    int p = (int)(lower_bound(sh, sh + n, Obj(0, bu[j].size, 0), cmpSize) - sh);
    while (p < n &&
           (sh[p].size == bu[j].size || sh[p].size == bu[j].size + 1)) {
      if (sh[p].money <= bu[j].money) e[sh[p].id].push_back(bu[j].id);
      ++p;
    }
  }
  sort(sh, sh + n, cmpMoney);
  solve();
  return 0;
}
