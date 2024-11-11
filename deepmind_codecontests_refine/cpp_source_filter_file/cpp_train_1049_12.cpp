#include <bits/stdc++.h>
using namespace std;
void Make_tree(int n, int d, int k) {
  if (d > n - 1) {
    cout << "No";
    return;
  }
  vector<int> deg(n);
  vector<pair<int, int> > ans;
  set<pair<int, int> > q;
  for (int i = 0; i < d; ++i) {
    ++deg[i];
    ++deg[i + 1];
    if (deg[i] > k || deg[i + 1] > k) {
      cout << "NO" << endl;
      return;
    }
    ans.push_back(make_pair(i, i + 1));
  }
  for (int i = 1; i < d; ++i) q.insert(make_pair(max(i, d - i), i));
  for (int i = d + 1; i < n; ++i) {
    while (!q.empty() && deg[q.begin()->second] == k) q.erase(q.begin());
    if (q.empty() || q.begin()->first == d) {
      cout << "No";
      return;
    }
    ++deg[i];
    ++deg[q.begin()->second];
    ans.push_back(make_pair(i, q.begin()->second));
    q.insert(make_pair(q.begin()->first + 1, i));
  }
  cout << "YES" << endl;
  for (int i = 0; i < n - 1; ++i)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
}
int main() {
  int n, d, k;
  cin >> n >> d >> k;
  Make_tree(n, d, k);
  return 0;
}
