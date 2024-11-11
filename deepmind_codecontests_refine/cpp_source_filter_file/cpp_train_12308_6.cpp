#include <bits/stdc++.h>
using namespace std;
map<long long, set<pair<long long, long long>>> dic;
long long mas[200010];
int main() {
  long long n;
  cin >> n;
  long long a;
  for (long long i = 0; i < n; i++) {
    cin >> mas[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> a;
    dic[mas[i]].insert({a, i});
  }
  long long ans = 0;
  set<pair<long long, long long>, greater<pair<long long, long long>>> vec;
  set<pair<long long, long long>> todel;
  long long kil = 0;
  long long prev = -1;
  dic[9999999].insert({0, -10});
  for (auto x : dic) {
    if (prev != -1) {
      auto y = vec.begin();
      for (long long i = 0; i < min(x.first - prev - 1, (long long)vec.size());
           i++) {
        kil -= y->first;
        todel.insert(*y);
        y++;
        ans += kil;
      }
    }
    for (auto y : todel) {
      vec.erase(y);
    }
    todel.clear();
    for (auto y : x.second) {
      vec.insert(y);
      kil += y.first;
    }
    for (auto y : vec) {
      vec.erase(y);
      kil -= y.first;
      ans += kil;
      prev = x.first;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
