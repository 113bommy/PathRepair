#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  vector<int> div1;
  vector<int> div2;
  if (m == 0) {
    cout << n - 1;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    div1.push_back(max(u, v));
    div2.push_back(min(u, v));
  }
  sort(div1.begin(), div1.end());
  sort(div2.begin(), div2.end());
  int raz = div1[0] - div2[div2.size() - 1];
  cout << max(raz, 0);
}
