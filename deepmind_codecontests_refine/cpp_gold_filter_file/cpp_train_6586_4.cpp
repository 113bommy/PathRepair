#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
const int MAXN = 5111;
vector<int> a;
int n;
int factor(int l, int r, int pre) {
  if (l > r) return 0;
  int id = min_element(a.begin() + l, a.begin() + r + 1) - a.begin();
  return min(r - l + 1,
             factor(l, id - 1, a[id]) + factor(id + 1, r, a[id]) + a[id] - pre);
}
int main() {
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << factor(1, n, 0);
}
