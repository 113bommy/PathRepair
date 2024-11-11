#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> v;
  for (int i = 0; i < (int)(s.size()); i++) {
    if (s[i] == '0') {
      v.push_back(i);
    }
  }
  int minn = (int)(1e8);
  ;
  for (int i = 0; i < (int)(v.size()) - (k + 1) + 1; i++) {
    auto it = lower_bound(v.begin(), v.end(), ((v[i] + v[i + k]) / 2));
    int a = max(*it - v[i], v[i + k] - *it);
    it--;
    int b = max(*it - v[i], v[i + k] - *it);
    minn = min(min(a, b), minn);
  }
  cout << minn;
}
