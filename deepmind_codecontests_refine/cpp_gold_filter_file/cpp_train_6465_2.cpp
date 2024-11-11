#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
bool check(int k) {
  int x[1010];
  for (int i = 1; i <= n; i++) {
    x[(i - 1)] = a[i] - a[i - 1];
    if (x[(i - 1) % k] == a[i] - a[i - 1])
      continue;
    else
      return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = 0;
  for (int k = 1; k <= n; k++)
    if (check(k)) s.insert(k);
  cout << s.size() << endl;
  for (auto u : s) cout << u << " ";
}
