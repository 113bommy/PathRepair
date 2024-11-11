#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string ar[n + 9];
  for (int i = 1; i <= n; i++) cin >> ar[i];
  int mx = 1;
  for (int i = 0; i < 7; i++) {
    map<char, int> mp;
    for (int j = 1; j <= n; j++) mp[ar[j][i]]++;
    mx = max(mx, mp['1']);
  }
  cout << mx << endl;
  return 0;
}
