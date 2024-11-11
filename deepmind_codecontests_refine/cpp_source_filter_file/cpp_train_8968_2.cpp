#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s = '!' + s;
  long long int xxx = s.size(), i;
  long long int sum = 0, second;
  long long int x = 0;
  long long int dd, ppp = 0;
  vector<long long int> v;
  for (i = 1; i < xxx; i++) {
    if (s[i] == 'v' && s[i - 1] == 'o') {
      x = 1;
      ppp = 1;
    } else if (s[i] == 'v')
      x++, ppp = 1;
    if (s[i] == 'o' && ppp == 0) continue;
    if (s[i] == 'o' && s[i - 1] == 'v') {
      long long int k = x - 1;
      sum = sum + k;
      dd = k;
      v.push_back(sum);
    } else if (s[i] == 'o' && s[i - 1] == 'o')
      v.push_back(dd);
  }
  if (s[xxx - 1] == 'v') {
    long long int k = x - 1;
    sum = sum + k;
  }
  long long int zz = v.size();
  long long int ans = 0;
  for (i = 0; i < zz; i++) {
    ans = ans + (v[i] * (sum - v[i]));
  }
  cout << ans;
}
