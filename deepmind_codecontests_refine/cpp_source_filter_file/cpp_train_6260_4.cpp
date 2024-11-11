#include <bits/stdc++.h>
using namespace std;
int a[300001];
int main() {
  int n;
  cin >> n;
  map<int, int> mp[2];
  mp[0][0]++;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[i + 1] = a[i] ^ tmp;
    mp[(i + 1) % 2][a[i + 1]]++;
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++)
    for (auto it : mp[i]) {
      ans += (it.second * (it.second - 1)) / 2;
    }
  cout << ans;
  return 0;
}
