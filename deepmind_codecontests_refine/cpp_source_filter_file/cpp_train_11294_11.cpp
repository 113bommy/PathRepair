#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
set<pair<int, int> > second;
int n, k, a[N], ans[N];
int main() {
  cin >> n;
  for (k = 1; k <= n; k++) {
    cin >> a[k];
    second.insert({a[k] + k, k});
  }
  for (k = 1; k <= n; k++) {
    pair<int, int> c = *second.begin();
    ans[k] = a[c.second] + c.second - k;
    if (ans[k] < ans[k - 1]) {
      cout << ": (";
      return 0;
    }
    second.erase(c);
  }
  for (k = 1; k <= n; k++) cout << ans[k] << " ";
}
