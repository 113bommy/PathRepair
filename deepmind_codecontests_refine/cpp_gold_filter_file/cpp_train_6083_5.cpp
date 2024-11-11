#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > f(int n, int p) {
  vector<pair<int, int> > ans;
  if (n == 5) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) ans.push_back(pair<int, int>(i, j));
    }
    return ans;
  }
  vector<pair<int, int> > vec = f(n - 1, p);
  ans.insert(ans.end(), vec.begin(), vec.end());
  int cnt = ans.size();
  for (int i = 1; i < n && ans.size() < (2 * n) + p; i++)
    ans.push_back(pair<int, int>(i, n));
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int> > vec = f(n, p);
    for (int i = 0; i < vec.size(); i++)
      cout << vec[i].first << ' ' << vec[i].second << endl;
  }
  return 0;
}
