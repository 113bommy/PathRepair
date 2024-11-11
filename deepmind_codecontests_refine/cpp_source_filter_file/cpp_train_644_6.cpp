#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, x;
  cin >> q >> x;
  unordered_map<int, int> mp;
  int ans = 0;
  int temp = 0, itr = 1;
  while (q--) {
    int a;
    cin >> a;
    a = a % x;
    mp[a]++;
    while (mp[temp] == itr) {
      temp = (temp + 1) % x;
      ans++;
      if (temp == 0) {
        itr++;
      }
    }
    cout << ans << endl;
  }
}
