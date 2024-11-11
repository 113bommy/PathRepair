#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, c, d;
  cin >> n >> m >> a >> b >> c >> d;
  if (m < n + 1 || n == 4) return cout << -1, 0;
  vector<int> ans;
  cout << a << " " << c << " ";
  for (int i = 1; i <= n; i++)
    if (i != a && i != b && i != c && i != d) {
      ans.push_back(i);
      cout << i << " ";
    }
  cout << d << " " << b << '\n' << c << " " << a << " ";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << b << " " << d;
}
