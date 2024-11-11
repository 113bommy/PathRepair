#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int INF = (int)1e9;
const long long IINF = LLONG_MAX;
const int maxn = 10000005;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> mp;
  if (n == 1) {
    if (a[0] == 0)
      cout << "cslnb";
    else {
      if (a[0] % 2)
        cout << "cslnb";
      else
        cout << "sjfnb";
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  if (mp[0] > 1) {
    cout << "cslnb";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (mp[a[i]] > 2 || (mp[a[i]] > 1 && mp[a[i] - 1] > 0)) {
      cout << "cslnb";
      return 0;
    }
  }
  int ct = 0;
  for (auto it : mp) {
    if (it.second >= 2) ct++;
  }
  if (ct >= 2) {
    cout << "cslnb";
    return 0;
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    assert(a[i] >= i);
    sum += abs(a[i] - i);
  }
  if (sum % 2)
    cout << "sjfnb";
  else
    cout << "cslnb";
}
