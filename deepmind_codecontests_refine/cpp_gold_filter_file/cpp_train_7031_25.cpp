#include <bits/stdc++.h>
using namespace std;
set<int> getdigits(int a) {
  set<int> ans;
  while (a) {
    ans.insert(a % 10);
    a /= 10;
  }
  return ans;
}
bool compare(const set<int> &a, const set<int> &b) {
  for (auto &x : b) {
    if (a.count(x)) {
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int p[4], a, b;
  for (int i = 0; i < 4; i++) {
    cin >> p[i];
  }
  cin >> a >> b;
  int mn = *min_element(p, p + 4);
  if (b >= mn)
    cout << max(0, mn - a);
  else
    cout << (b - a + 1);
}
