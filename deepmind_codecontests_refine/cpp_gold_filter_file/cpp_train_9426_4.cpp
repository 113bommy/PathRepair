#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<int, int>::iterator it;
map<int, int> co;
int n, k;
int a[111111];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    mp[a[i]]++;
    if (mp[a[i]] == 1) {
      co.insert(pair<int, int>(a[i], 1));
    } else {
      if (co.find(a[i]) != co.end()) co.erase(a[i]);
    }
  }
  it = co.end();
  if (it != co.begin()) it--;
  if (co.empty())
    cout << "Nothing" << endl;
  else
    cout << it->first << endl;
  for (int i = k + 1; i <= n; i++) {
    mp[a[i]]++;
    mp[a[i - k]]--;
    if (mp[a[i]] == 1) {
      co.insert(pair<int, int>(a[i], 1));
    } else {
      if (co.find(a[i]) != co.end()) co.erase(a[i]);
    }
    if (mp[a[i - k]] == 1) {
      co.insert(pair<int, int>(a[i - k], 1));
    } else {
      if (co.find(a[i - k]) != co.end()) co.erase(a[i - k]);
    }
    it = co.end();
    if (it != co.begin()) it--;
    if (co.empty())
      cout << "Nothing" << endl;
    else
      cout << it->first << endl;
  }
  return 0;
}
