#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> sol;
int n, d, k, r;
int sub2(int s, int d) {
  vector<int> D;
  D.push_back(0);
  int i{};
  while (r) {
    int j = i + 1;
    int p = (j - 1) / (k - 1);
    int e = D[p] + 1;
    if (e > d) break;
    sol.push_back({s + p, s + j});
    D.push_back(e);
    i = j;
    r--;
  }
  return s + i;
}
int sub(int s, int d) {
  int t = s;
  auto w = min(k - 2, r);
  r -= w;
  for (int x = 0; x < w; x++) {
    sol.push_back({s, t + 1});
    t = sub2(t + 1, d - 1);
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin >> n >> d >> k;
  if (n < d + 1) {
    cout << "NO\n";
    return 0;
  }
  if (k == 1) {
    if (d > 1)
      cout << "NO\n";
    else
      cout << "YES\n1 2\n";
    return 0;
  }
  r = n - d - 1;
  int a{1}, b{2};
  for (int i = 0; i < d - 1; i++) {
    sol.push_back({a, b});
    a = b;
    b = sub(b, min(d - i - 1, i + 1)) + 1;
  }
  sol.push_back({a, b});
  if (b != n)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto [a, b] : sol) cout << a << ' ' << b << '\n';
  }
}
