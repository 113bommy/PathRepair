#include <bits/stdc++.h>
using namespace std;
int n, t, ans;
vector<int> v[102], vec;
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (int i = 1; i <= t; i++) {
    vector<int> temp;
    for (int j = 0; j < ((int)vec.size()) / 2; j++)
      temp.push_back(vec[2 * j] + vec[2 * j + 1]);
    if (((int)vec.size()) % 2) temp.push_back(vec[((int)vec.size()) - 1]);
    for (auto u : v[i]) temp.push_back(u);
    sort(temp.begin(), temp.end(), greater<int>());
    vec.clear();
    int pt = ((int)temp.size());
    if ((t - i) < 30) pt = min(pt, (1 << (t - i)));
    for (int j = 0; j < pt; j++) vec.push_back(temp[j]);
    if (i == t)
      for (auto u : vec) ans += u;
    temp.clear();
  }
  cout << ans;
  return 0;
}
