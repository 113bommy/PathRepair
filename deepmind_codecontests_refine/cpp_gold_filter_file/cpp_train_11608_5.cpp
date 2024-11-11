#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, pair<int, int> > > has(1000005, {0, {n, -1}});
  vector<int> arr(n);
  int a;
  int maxc = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[i] = a;
    has[a].first++;
    maxc = max(maxc, has[a].first);
    has[a].second.first = min(has[a].second.first, i);
    has[a].second.second = max(has[a].second.second, i);
  }
  int len = INT_MAX;
  int l = 1, r = n;
  for (int i = 1; i <= 1000000; i++) {
    if (has[i].first == maxc) {
      if (len > (has[i].second.second - has[i].second.first + 1)) {
        len = has[i].second.second - has[i].second.first + 1;
        l = has[i].second.first + 1;
        r = has[i].second.second + 1;
      }
    }
  }
  cout << l << " " << r;
}
