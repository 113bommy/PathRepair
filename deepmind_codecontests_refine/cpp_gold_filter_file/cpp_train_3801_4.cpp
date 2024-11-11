#include <bits/stdc++.h>
using namespace std;
vector<pair<unsigned long long int, unsigned long long int> > ans;
int main() {
  unsigned long long int x, m;
  cin >> x;
  ans.push_back({1, x});
  if (x != 1) {
    ans.push_back({x, 1});
  }
  for (unsigned long long int i = 2; (i) <= 3000000; i++) {
    unsigned long long int num = 6 * x - i + (i * i * i);
    unsigned long long int den = 3 * ((i * i) + (i));
    if (num % den == 0) {
      m = (num / den);
      if (m * i <= (x) && i <= m) {
        ans.push_back(make_pair(i, m));
        if (i != m) {
          ans.push_back(make_pair(m, i));
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}
