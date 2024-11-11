#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
  int i, n;
  ios::sync_with_stdio(false);
  cin >> n;
  long long ans = 0;
  while (n > 0) {
    n--;
    string str;
    cin >> str;
    int cnf = 0;
    for (auto it : str) {
      cnf ^= (1 << (it - 'a'));
    }
    ans += mp[cnf];
    for (i = 0; i < 26; i++) {
      ans += mp[cnf ^ (1 << i)];
    }
    mp[cnf]++;
    cout << ans << "\n";
  }
  return 0;
}
