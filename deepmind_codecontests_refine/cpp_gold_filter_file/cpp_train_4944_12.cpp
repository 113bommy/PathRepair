#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)1e18 + 19;
const long long int mod = (long long int)1e9 + 7;
void cazz() {
  long long int t = 1, i, j, n;
  cin >> n;
  long long int cnt = 0, ans = -1;
  vector<long long int> v1, v2;
  cin >> t;
  while (t--) cin >> j, v1.push_back(j);
  cin >> t;
  while (t--) cin >> j, v2.push_back(j);
  vector<long long int>::iterator it1, it2;
  t = 10000;
  while (t--) {
    if (v1.size() == 0) {
      ans = 2;
      break;
    } else if (v2.size() == 0) {
      ans = 1;
      break;
    }
    if (v1[0] > v2[0])
      v1.push_back(v2[0]), v1.push_back(v1[0]);
    else if (v2[0] > v1[0])
      v2.push_back(v1[0]), v2.push_back(v2[0]);
    it1 = v1.begin(), it2 = v2.begin();
    v1.erase(it1), v2.erase(it2);
    cnt++;
  }
  if (ans == -1)
    cout << -1;
  else
    cout << cnt << ' ' << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cazz();
  return 0;
}
