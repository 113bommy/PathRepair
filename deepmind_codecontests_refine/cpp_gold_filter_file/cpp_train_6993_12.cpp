#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  int a[n];
  int q;
  cin >> q;
  map<int, int> last;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    last[a[i]] = i;
  }
  vector<pair<int, int>> v;
  int bg = 0, ed = last[a[0]];
  for (int i = 0; i < n; i++) {
    if (i == ed) {
      v.push_back({bg, ed});
      bg = i + 1;
      if (i != n - 1) ed = last[a[i + 1]];
    } else {
      ed = max(ed, last[a[i]]);
    }
  }
  long long ans = 0;
  for (auto it : v) {
    int start = it.first;
    int end = it.second;
    int mx = -1;
    map<int, int> mp;
    for (int i = start; i <= end; i++) {
      mp[a[i]]++;
      mx = max(mx, mp[a[i]]);
    }
    long long siz = end - start + 1;
    ans += (siz - mx);
  }
  cout << ans << "\n";
  return 0;
}
