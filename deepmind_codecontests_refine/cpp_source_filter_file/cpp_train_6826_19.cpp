#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, mx = 0, ans = 0, c, d, e, succ, fail;
  string name;
  cin >> n;
  map<string, long long> mp;
  vector<string> vec;
  pair<long long, string> pr[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> name >> succ >> fail >> a >> b >> c >> d >> e;
    vec.push_back(name);
    mx = succ * 100 - fail * 50 + a + b + c + d + e;
    mp[name] = mx;
    ans = max(mx, ans);
  }
  for (int i = 0; i < vec.size(); i++) {
    if (mp[vec[i]] == ans) {
      cout << vec[i] << endl;
    }
  }
  return 0;
}
