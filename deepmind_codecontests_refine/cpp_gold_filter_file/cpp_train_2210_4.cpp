#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  long long mp[11] = {0}, mn[11] = {0};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t >= 0)
      ++mp[t];
    else
      ++mn[-t];
  }
  long long sum = 0;
  if (mp[0] > 1) sum += (mp[0] * (mp[0] - 1)) / 2;
  for (int i = 1; i < 11; ++i) sum += mp[i] * mn[i];
  cout << sum << endl;
  return 0;
}
