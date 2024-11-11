#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
  int n, i, k, ans = 0;
  map<string, string> mp;
  map<string, string>::iterator it;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    k = 0;
    for (it = mp.begin(); it != mp.end(); ++it) {
      if (it->second == a) {
        mp[it->first] = b;
        k = 1;
        break;
      }
    }
    if (k == 0) {
      mp[a] = b;
      ans++;
    }
  }
  printf("%d\n", ans);
  for (it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << " " << it->second << '\n';
  return 0;
}
