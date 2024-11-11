#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using VI = vector<int>;
using VII = vector<vector<int> >;
VI c(int u, int v, int w, int z = 0) {
  VI ans;
  ans.push_back(u);
  ans.push_back(v);
  ans.push_back(w);
  if (z) ans.push_back(z);
  return ans;
}
VII c3() {
  vector<VI> ans;
  ans.push_back(c(1, 2, 3));
  ans.push_back(c(1, 2, 3));
  return ans;
}
VII c4() {
  vector<VI> ans;
  ans.push_back(c(1, 2, 3));
  ans.push_back(c(1, 2, 4));
  ans.push_back(c(1, 3, 4));
  ans.push_back(c(2, 3, 4));
  return ans;
}
VII c5() {
  vector<VI> ans;
  ans.push_back(c(5, 4, 2));
  ans.push_back(c(3, 1, 5));
  ans.push_back(c(4, 5, 2, 3));
  ans.push_back(c(4, 3, 2, 1));
  ans.push_back(c(4, 2, 1));
  ans.push_back(c(3, 1, 5));
  return ans;
}
VII c6() {
  VII ans;
  ans.push_back(c(1, 2, 3));
  ans.push_back(c(4, 5, 6));
  ans.push_back(c(1, 5, 2, 4));
  ans.push_back(c(1, 6, 3, 4));
  ans.push_back(c(2, 6, 3, 5));
  ans.push_back(c(1, 2, 4, 5));
  ans.push_back(c(2, 3, 5, 6));
  ans.push_back(c(1, 3, 4, 6));
  return ans;
}
VII calc(int n) {
  if (n == 3) return c3();
  if (n == 4) return c4();
  if (n == 5) return c5();
  if (n == 6) return c6();
  auto ans = calc(n - 4);
  auto p = calc(4);
  for (auto q : p) {
    for (auto &u : q) u += n - 4;
    ans.push_back(q);
  }
  for (int i = 1; i <= n - 4; i++) {
    int u = i, v = i + 1;
    if (i == n - 4) v = 1;
    ans.push_back(c(n - 3, u, n - 2, v));
    ans.push_back(c(n - 1, u, n, v));
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  auto p = calc(n);
  cout << p.size() << endl;
  for (auto ans : p) {
    printf("%d ", ans.size());
    for (auto u : ans) printf("%d ", u);
    puts("");
  }
}
