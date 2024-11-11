#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int o = 0, c = 0;
  vector<int> v;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      o++;
      v.push_back(1);
    } else {
      c++;
      v.push_back(-1);
    }
  }
  int count = 0, bal = 0;
  if (o != c)
    cout << -1 << endl;
  else {
    for (int i = 0; i < n; i++) {
      bal += v[i];
      if (bal < 0)
        count++;
      else {
        if (count != 0) res.push_back(count + 1);
        count = 0;
      }
    }
    long long ans = 0;
    for (int i = 0; i < res.size(); i++) {
      ans += res[i];
    }
    cout << ans << endl;
  }
}
