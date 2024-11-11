#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v(101, 0);
bool a[101] = {0};
list<int> ans;
int main() {
  cin >> n >> m;
  for (int i = 0, t1, t2; i < n; i++) {
    cin >> t1 >> t2;
    v[t1]++;
    v[t2]--;
    a[t2] = 1;
  }
  for (int i = 1; i < m; i++) {
    v[i] += v[i - 1];
    if (!v[i] && !a[i]) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto el : ans) cout << el << " ";
  return 0;
}
