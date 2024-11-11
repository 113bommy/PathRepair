#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<long long, long long> mp;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  int pos = find(v.begin(), v.end(), m) - v.begin();
  long long ans = 0;
  int lft = 0, rgt = 0, len = 1;
  int i = pos, j = pos;
  while (i >= 0) {
    if (len % 2 == 1) {
      if (lft == rgt) ans++;
    } else {
      if (lft == rgt - 1) ans++;
    }
    i--;
    if (i >= 0) {
      if (v[i] < m)
        lft++;
      else
        rgt++;
      mp[lft - rgt]++;
    }
    len++;
  }
  j = pos;
  lft = 0, rgt = 0, len = 1;
  while (j < (int)v.size()) {
    if (len % 2 == 1) {
      if (lft == rgt) ans++;
    } else {
      if (lft == rgt - 1) ans++;
    }
    j++;
    len++;
    if (j < (int)v.size()) {
      if (v[j] < m)
        lft++;
      else
        rgt++;
    }
    if (j < (int)v.size()) {
      ans += mp[-(lft - rgt)];
      ans += mp[-(lft - rgt + 1)];
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
