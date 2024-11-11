#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    set<int> s;
    for (int i = 0; i < n; i++) cin >> v[i], mp[v[i]]++;
    vector<int> res;
    int sum = 0;
    int cap = n / 2;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s.count(v[i]) == 0) {
        if (ok == true) {
          if (sum + mp[v[i]] <= cap)
            sum += mp[v[i]], res.push_back(mp[v[i]]), s.insert(v[i]);
          else
            ok = false;
        } else
          ok = false;
      }
    }
    int a = 0;
    int b = 0;
    int c = 0;
    if (!res.empty()) a = res[0];
    ok = true;
    for (int i = 1; i < res.size(); i++) {
      if (b + res[i] <= a)
        b += res[i];
      else {
        b += res[i];
        break;
      }
    }
    c = sum - a - b;
    if (a > 0 && b > 0 && c > 0)
      cout << a << " " << b << " " << c << "\n";
    else
      cout << 0 << " " << 0 << " " << 0 << "\n";
  }
}
