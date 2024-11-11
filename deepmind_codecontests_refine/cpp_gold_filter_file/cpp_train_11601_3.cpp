#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0;
vector<pair<int, int> > store;
void go(int x, int y) {
  if (k == 0) return;
  k--;
  store.push_back(pair<int, int>(x, y));
  ans += abs(x - 1) + abs(y - 1) + 1;
  if (x - 1 == 0 || y + 1 == m + 1) return;
  go(x - 1, y + 1);
}
void print(int x, int y) {
  for (int i = 1; i < x + 1; i++) {
    printf("(%d,%d) ", i, 1);
  }
  for (int i = 2; i < y + 1; i++) printf("(%d,%d) ", x, i);
  printf("\n");
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i < n + 1; i++) go(i, 1);
  for (int i = 2; i < m + 1; i++) go(n, i);
  cout << ans << endl;
  for (int i = store.size() - 1; i >= 0; i--) {
    print(store[i].first, store[i].second);
  }
  return 0;
}
