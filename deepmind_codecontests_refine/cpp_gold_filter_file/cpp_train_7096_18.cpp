#include <bits/stdc++.h>
using namespace std;
int n, m;
bool sorted[1001];
vector<int> x, y;
int ans[1001];
int main() {
  cin >> n >> m;
  while (m--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t) {
      for (int i = a; i < b; i++) sorted[i] = true;
    } else {
      x.push_back(a);
      y.push_back(b);
    }
  }
  ans[1] = n;
  for (int i = 2; i <= n; i++) {
    if (sorted[i - 1])
      ans[i] = ans[i - 1];
    else
      ans[i] = ans[i - 1] - 1;
  }
  for (int i = 0; i < x.size(); i++) {
    if (ans[x[i]] == ans[y[i]]) return cout << "NO", 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
