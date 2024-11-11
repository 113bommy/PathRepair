#include <bits/stdc++.h>
using namespace std;
const int mx = 1111111;
int ans[mx];
int main(int argc, char const *argv[]) {
  int n, b;
  scanf("%d%d", &n, &b);
  long long tim = 0;
  queue<pair<int, int> > store;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    while (tim <= x && !store.empty()) {
      pair<int, int> s = store.front();
      tim += s.first;
      ans[s.second] = tim;
      store.pop();
    }
    if (store.empty()) {
      if (tim <= x)
        tim = x + y, ans[i] = tim;
      else
        store.push(make_pair(y, i));
    } else {
      if (store.size() < b)
        store.push(make_pair(y, i));
      else
        ans[i] = -1;
    }
  }
  while (!store.empty()) {
    pair<int, int> s = store.front();
    tim += s.first;
    ans[s.second] = tim;
    store.pop();
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  printf("\n");
  return 0;
}
