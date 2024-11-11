#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> mp;
  int n, a, b, i;
  cin >> n;
  int ans;
  n >= 2 ? ans = 2 : ans = n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    mp[a] = b;
  }
  map<int, int>::iterator it, temp;
  it = mp.begin();
  it++;
  temp = it;
  for (i = 1; i < n - 1; i++) {
    temp++;
    a = it->first;
    b = it->second;
    if (mp.lower_bound(a - b) == temp) {
      ans++;
    } else if (a + b < temp->first) {
      ans++;
      mp[a + b] = 1;
      it++;
    }
    it++;
    temp = it;
  }
  cout << ans;
}
