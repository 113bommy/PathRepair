#include <bits/stdc++.h>
using namespace std;
int n;
int a[110000];
map<long long, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0, _i = (n); i < _i; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a, a + n);
  if (a[0] == a[2]) {
    int x = a[0];
    long long c = mp[x];
    long long res = c * (c - 1) / 2 * (c - 2) / 3;
    cout << res << endl;
    return 0;
  }
  if (a[1] == a[2]) {
    int x = a[1];
    long long c = mp[x];
    long long res = c * (c - 1) / 2;
    cout << res << endl;
    return 0;
  }
  int x = a[2];
  long long c = mp[x];
  cout << c << endl;
  return 0;
}
