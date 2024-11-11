#include <bits/stdc++.h>
using namespace std;
long long int limit = 1500000;
vector<pair<long long int, long long int> > ans;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b, c, x, i, j, k, n, m;
  cin >> x;
  long long int cnt = 0;
  long long int cur = 0;
  long long int other = 0;
  for (i = 1; i <= limit; i++) {
    cur = 6 * x - i + i * i * i;
    other = 3 * i * i + 3 * i;
    if ((cur) % other == 0 && i <= cur / other &&
        i * (i + 1) * (3 * (cur / other) - i + 1) / 6 == x) {
      ans.push_back(make_pair((cur) / other, i));
      if ((cur) / other != i) {
        ans.push_back(make_pair(i, (cur) / other));
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
