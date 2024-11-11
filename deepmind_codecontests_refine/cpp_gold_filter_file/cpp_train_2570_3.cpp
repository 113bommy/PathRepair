#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int x = n / m;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i] % m].push_back(i);
  }
  long long move = 0;
  vector<pair<int, int>> f;
  for (int i = 0; i < 2 * m; i++) {
    int k = i % m;
    while (mp[k].size() > x) {
      int g = mp[k].back();
      mp[k].pop_back();
      f.push_back(make_pair(i, g));
    }
    while (mp[k].size() < x && !f.empty()) {
      pair<int, int> p = f.back();
      int g = p.second;
      int mod = p.first;
      f.pop_back();
      mp[k].push_back(g);
      a[g] += (i - mod);
      move = move + (i - mod);
    }
  }
  cout << move << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
