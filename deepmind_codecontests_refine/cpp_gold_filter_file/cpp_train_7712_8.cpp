#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n + 10], s = 0;
  map<long long int, long long int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
    mp[s] = i;
  }
  long long int mx = -1;
  s = 0;
  for (int i = n; i >= 0; i--) {
    s += a[i];
    if (mp[s] != 0) {
      if (mp[s] < i) {
        if (mx < s) mx = s;
      }
    }
  }
  if (mx == -1)
    cout << 0 << endl;
  else
    cout << mx << endl;
}
