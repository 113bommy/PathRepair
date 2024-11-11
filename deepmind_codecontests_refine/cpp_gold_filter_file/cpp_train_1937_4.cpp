#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
long long a[100100];
map<int, long long> mp;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a, a + n);
  if (mp[a[0]] > 2)
    cout << (mp[a[0]] - 2) * (mp[a[0]] - 1) * mp[a[0]] / 6 << endl;
  else if (mp[a[0]] == 2)
    cout << mp[a[2]] << endl;
  else if (mp[a[1]] > 1)
    cout << mp[a[1]] * (mp[a[1]] - 1) / 2 << endl;
  else
    cout << mp[a[2]] << endl;
  return 0;
}
