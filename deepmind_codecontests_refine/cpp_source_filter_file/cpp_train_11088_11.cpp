#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int> > v;
  int nu = s[0] - '0';
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (nu == (s[i] - '0'))
      c++;
    else {
      v.push_back({nu, c});
      c = 1;
      nu = s[i] - '0';
    }
  }
  v.push_back({nu, c});
  int ans = v.size();
  int fl = 1;
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second > 2) {
      fl = 0;
      break;
    }
    if (v[i].second > 1) cnt++;
  }
  if (cnt >= 2 || fl == 0)
    cout << ans + 2;
  else {
    if (cnt > 1)
      cout << ans + 1;
    else
      cout << ans;
  }
}
