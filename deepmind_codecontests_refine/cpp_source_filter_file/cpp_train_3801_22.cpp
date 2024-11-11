#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  unsigned long long x;
  cin >> x;
  vector<pair<unsigned long long, unsigned long long> > ans;
  for (unsigned long long i = 1; i <= 1000000; i++) {
    unsigned long long hey = (x) - ((i * (i + 1) * (2 * i + 1))) / 6;
    hey -= ((i + 1) * i);
    hey += (((i + 2) * (i) * (i + 1)) / 2);
    unsigned long long foo = i * i + i - (i * (i + 1)) / 2;
    if (foo == 0) continue;
    if (hey % foo != 0) continue;
    unsigned long long res = hey / foo;
    if (res >= i) {
      ans.push_back(make_pair(i, res));
      if (res != i) ans.push_back(make_pair(res, i));
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (unsigned long long i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
