#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int maxn = 3e5 + 5;
int n;
int w[maxn];
int pos[maxn];
vector<pair<int, int>> ans;
void add(int a, int b) {
  pair<int, int> t = {a, b};
  ans.push_back(t);
  swap(w[a], w[b]);
  swap(pos[w[a]], pos[w[b]]);
}
void solve(int a, int b) {
  if (a > b) swap(a, b);
  if (abs(a - b) >= n / 2) {
    add(a, b);
    return;
  }
  if (b <= n / 2) {
    add(b, n);
    add(a, n);
    add(b, n);
    return;
  }
  if (a >= n / 2 + 1) {
    add(1, b);
    add(1, a);
    add(1, b);
    return;
  }
  add(1, b);
  add(a, n);
  add(1, n);
  add(1, b);
  add(a, n);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    pos[w[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (pos[i] != i) {
      solve(i, pos[i]);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
