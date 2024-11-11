#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, l, m, n, cnt = 0;
  cin >> n;
  string s, ss;
  map<string, long long int> mp;
  for (i = 0; i < n; i++) {
    cin >> s;
    cin >> ss;
    s = s + ss;
    mp[s]++;
    if (mp[s] == 1) {
      cnt++;
    }
  }
  cout << cnt;
}
