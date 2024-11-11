#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n = 0, m = 0, k = 0, i = 0, j = 0, p = 0, q = 0, x = 0, y = 0,
                a = 0, b = 0, z = 0, ans = 0, cnt = 0;
  string s;
  bool flag = false;
  cin >> n >> a >> b;
  vector<long long int> v;
  v.push_back(1);
  cnt = 1;
  x = 1;
  if (b == 0 && a > max((long long int)0, n - 2)) flag = true;
  for (i = 0; i < b; i++) {
    x = cnt + 1;
    v.push_back(x);
    cnt += x;
    if (x > 50000) flag = true;
  }
  if (b == 0 && a != 0) {
    v.push_back(1);
  }
  for (i = 0; i < a; i++) {
    x++;
    v.push_back(x);
    if (x > 50000) flag = true;
  }
  if (flag)
    cout << -1 << endl;
  else {
    for (i = v.size(); i < n; i++) v.push_back(x);
    for (auto u : v) cout << u << " ";
    cout << endl;
  }
  return 0;
}
