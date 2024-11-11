#include <bits/stdc++.h>
using namespace std;
const int TAM = 3e5 + 10;
int used[TAM];
int a[TAM], b[TAM];
long long ans;
set<pair<int, int> > one, two;
set<pair<int, int> >::iterator it;
void removeOne() {
  int idx;
  it = one.begin();
  ans += (*it).first;
  idx = (*it).second;
  one.erase(it);
  if (used[idx] == 0) {
    two.erase(two.find(make_pair(b[idx], idx)));
    one.insert(make_pair(b[idx] - a[idx], idx));
  }
  used[idx]++;
}
void removeTwo() {
  int idx;
  it = two.begin();
  ans += (*it).first;
  idx = (*it).second;
  two.erase(it);
  one.erase(one.find(make_pair(a[idx], idx)));
  used[idx] = 2;
}
int main() {
  int n, w;
  int j;
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    one.insert(make_pair(a[i], i));
    two.insert(make_pair(b[i], i));
    used[i] = 0;
  }
  ans = 0;
  int op1, op2;
  while (w) {
    if ((w & 1) == 0 && one.size() > 1 && two.size()) {
      it = one.begin();
      op1 = (*it).first;
      it++;
      op1 += (*it).first;
      it = two.begin();
      if (op1 < (*it).first) {
        removeOne();
        removeOne();
      } else
        removeTwo();
      w--;
    } else
      removeOne();
    w--;
  }
  printf("%I64d\n", ans);
  for (int i = 0; i < n; i++) printf("%d", used[i]);
  return 0;
}
