#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> vec;
  int max = -1;
  int idx = 0;
  long long int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
    if (x > max) {
      max = x;
      idx = i;
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < idx; i++) {
    if (vec[0] > vec[1]) {
      ans.push_back(make_pair(vec[0], vec[1]));
      int c = vec[1];
      vec.erase(vec.begin() + 1);
      vec.push_back(c);
    } else {
      ans.push_back(make_pair(vec[0], vec[1]));
      int c = vec[0];
      vec.erase(vec.begin());
      vec.push_back(c);
    }
  }
  while (q > 0) {
    cin >> x;
    if (x < idx + 1) {
      cout << ans[x - 1].first << " " << ans[x - 1].second << endl;
    } else {
      cout << max << " " << vec[1 + (x - idx - 1) % (n - 1)] << endl;
    }
    q--;
  }
  return 0;
}
