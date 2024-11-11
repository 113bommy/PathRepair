#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
map<int, int> mp;
int ans = 0;
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int x = 1; x <= 30; x++) {
    int now = ksm(2, x);
    mp.clear();
    for (int i = n; i >= 1; i--) {
      if (now < a[i]) {
        mp[a[i]]++;
        continue;
      }
      ans += mp[now - a[i]];
      mp[a[i]]++;
    }
  }
  cout << ans << endl;
  return 0;
}
