#include <bits/stdc++.h>
using namespace std;
int n;
int q, r1, l1, c;
int pos;
int ans = 0;
int x[13];
vector<int> v;
void check() {
  int sum = 0, l = v[0], r = v[v.size() - 1];
  for (int i = 0; i < v.size(); ++i) {
    sum += v[i];
  }
  if (sum >= r1 && sum <= l1 && (r - l) >= c) ans++;
}
void rec(int p) {
  if (p == n) return;
  rec(p + 1);
  v.push_back(x[p]);
  check();
  rec(p + 1);
  v.pop_back();
}
int main() {
  cin >> n >> r1 >> l1 >> c;
  for (int i = 0; i < n; ++i) cin >> x[i];
  sort(x, x + n);
  for (int i = 0; i < n; ++i) {
    v.clear();
    v.push_back(x[i]);
    rec(i + 1);
  }
  cout << ans << endl;
  return 0;
}
