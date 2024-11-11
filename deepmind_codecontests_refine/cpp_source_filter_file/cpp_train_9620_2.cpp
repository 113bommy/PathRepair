#include <bits/stdc++.h>
using namespace std;
string s;
long long ans = 0;
long long man, woman;
signed main() {
  long long i;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'F')
      i++;
    else
      break;
  }
  for (; i < s.size(); i++) {
    if (s[i] == 'F') {
      ans = max(woman + man, ans);
      woman++;
    } else {
      man++;
      (woman == 0) ? woman = 0 : --woman;
    }
  }
  cout << ans << endl;
  return 0;
}
