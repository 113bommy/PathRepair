#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int setBitNumber(int n) {
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n = n + 1;
  return (n >> 1);
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      int x = a[i];
      x = setBitNumber(x);
      mp[x]++;
    }
    long long sum = 0;
    for (auto u : mp) {
      int y = u.second;
      sum = sum + (1ll * y * (y - 1)) / 2;
    }
    cout << sum << endl;
    mp.clear();
  }
}
