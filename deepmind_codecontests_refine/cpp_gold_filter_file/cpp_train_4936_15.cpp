#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("input.txt");
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  vector<vector<int>> vec(2);
  for (int i = 1; i <= (k < v[1] / 2 ? k : v[1]); i++) vec[1].push_back(i);
  for (int i = vec[1][vec[1].size() - 1] + 1; i <= v[1] / 2; i++) {
    if (v[1] / i * i >= v[1] - k) vec[1].push_back(i);
  }
  for (int i = k < v[1] / 2 ? k : -1; i >= 0; i--) vec[1].push_back(v[1] - i);
  if (k < v[1])
    vec[1].erase(vec[1].begin(), vec[1].begin() + k - 1);
  else {
    vec[1].erase(vec[1].begin(), vec[1].end());
    vec[1].push_back(v[1]);
  }
  reverse(vec[1].begin(), vec[1].end());
  int ans = v[1];
  for (; ans >= 1;) {
    int i;
    for (i = 1; i <= n; i++) {
      if (v[i] % ans > k) {
        int tmp = v[i] / ans;
        tmp++;
        ans = v[i] / tmp;
        break;
      }
    }
    if (i == n + 1) break;
  }
  cout << ans << endl;
  cin.get();
}
