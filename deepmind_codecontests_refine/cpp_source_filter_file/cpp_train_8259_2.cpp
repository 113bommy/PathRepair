#include <bits/stdc++.h>
using namespace std;
int n, x, y;
list<int> l[200005];
pair<int, int> deger[200005], root;
bool mark[200005];
pair<int, int> init(int x) {
  pair<int, int> tmp, ret;
  ret.first = 0;
  ret.second = 0;
  list<int>::iterator it;
  for (it = l[x].begin(); it != l[x].end(); it++)
    if ((*it) > 0) {
      if (mark[*it] == 0) {
        mark[*it] = x;
        tmp = init(*it);
        ret.first += tmp.first;
        ret.second += tmp.second;
        ret.second++;
      }
    } else {
      if (mark[(*it) * -1] == 0) {
        mark[(*it) * -1] = x;
        tmp = init((*it) * -1);
        ret.first += tmp.first;
        ret.second += tmp.second;
        ret.first++;
      }
    }
  return ret;
}
void solve(int x, int ters) {
  deger[x] = pair<int, int>(ters, x);
  mark[x] = 1;
  list<int>::iterator it;
  for (it = l[x].begin(); it != l[x].end(); it++) {
    if (mark[(*it)] == 0) continue;
    if ((*it) > 0)
      solve(*it, ters + 1);
    else
      solve(*it * -1, ters - 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d %d", &x, &y);
    l[x].push_back(y);
    l[y].push_back(x * -1);
  }
  mark[1] = -1;
  root = init(1);
  for (int i = 1; i <= n; i++) mark[i] = 0;
  solve(1, root.first);
  sort(deger + 1, deger + n + 1);
  int last = deger[1].first;
  printf("%d\n", last);
  for (int i = 1; i <= n; i++)
    if (deger[i].first == last) {
      printf("%d ", deger[i].second);
    } else
      break;
}
