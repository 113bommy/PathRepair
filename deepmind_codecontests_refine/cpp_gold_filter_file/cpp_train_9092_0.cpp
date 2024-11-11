#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  bool t = false;
  int a = -1, b = -1, c = -1, d = -1, sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) t = true;
    v.push_back(x);
    sum += x;
  }
  if (!t) return cout << -1, 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    if (v[i] % 3 == 1 && a == -1)
      a = v[i];
    else if (v[i] % 3 == 1 && d == -1)
      d = v[i];
    else if (v[i] % 3 == 2) {
      if (b == -1)
        b = v[i];
      else if (c == -1)
        c = v[i];
    }
  }
  t = false;
  reverse(v.begin(), v.end());
  map<int, int> mp;
  if (sum % 3 == 1) {
    if (a == -1)
      mp[b]++, mp[c]++;
    else
      mp[a]++;
  } else if (sum % 3 == 2) {
    if (b == -1)
      mp[a]++, mp[d]++;
    else
      mp[b]++;
  }
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == 0 && t == false) return cout << 0, 0;
    if (mp[v[i]] > 0) {
      mp[v[i]]--;
      continue;
    }
    cout << v[i];
    t = true;
  }
  return 0;
}
