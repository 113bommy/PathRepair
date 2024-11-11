#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == '0') {
        v.push_back(-1);
      } else {
        v.push_back(1);
      }
    }
  }
  if (accumulate(v.begin(), v.end(), 0) != 0) {
    cout << -1 << endl;
    return 0;
  }
  int c1 = 0, c2 = 0;
  int ma1 = 0, ma2 = 0;
  for (int i = 0; i < v.size(); i++) {
    c1 += v[i];
    ma1 = max(ma1, c1);
    if (c1 < 0) c1 = 0;
  }
  for (int i = 0; i < v.size(); i++) {
    c2 -= (v[i]);
    ma2 = max(ma2, (c2));
    if (c2 < 0) c2 = 0;
  }
  cout << max(ma1, ma2) << endl;
}
