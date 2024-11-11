#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<set<int> > ar(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ar[a].insert(b);
    ar[b].insert(a);
  }
  vector<int> sizes;
  vector<bool> used(n, false);
  set<int> need;
  for (int i = 0; i < n; ++i) need.insert(i);
  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    need.erase(i);
    int beg = 0;
    int end = 1;
    q[0] = i;
    while (beg < end) {
      int cur = q[beg++];
      used[cur] = true;
      for (set<int>::iterator it = need.begin(); it != need.end();) {
        if (ar[cur].find(*it) == ar[cur].end()) {
          q[end++] = *it;
          need.erase(it++);
        } else {
          it++;
        }
      }
    }
    sizes.push_back(-end);
  }
  sort(sizes.begin(), sizes.end());
  cout << sizes.size() << endl;
  for (int i = 0; i < sizes.size(); ++i) {
    cout << -sizes[i] << " ";
  }
  cout << endl;
}
