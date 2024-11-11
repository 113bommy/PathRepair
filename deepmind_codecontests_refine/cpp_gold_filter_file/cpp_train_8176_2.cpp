#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int l, i, j, f[50] = {0}, flag = 0;
  string s;
  cin >> s;
  l = s.length();
  long long int flag2 = 0;
  for (i = 0; i + 26 <= l; i++) {
    vector<long long int> v;
    flag = 0;
    memset(f, 0, sizeof(f));
    for (j = i; j <= i + 25; j++) {
      if (s[j] != '?')
        f[s[j] - 'A']++;
      else
        f[30]++;
    }
    for (j = 0; j < 26; j++) {
      if (f[j] == 0) {
        if (f[30] >= 1) {
          f[30]--;
          f[j]++;
          v.push_back(j);
        } else {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      for (j = i; j <= i + 25; j++) {
        if (s[j] == '?') {
          s[j] = v[v.size() - 1] + 'A';
          v.pop_back();
        }
      }
      flag2 = 1;
      break;
    }
  }
  if (flag2 == 0)
    cout << -1;
  else {
    for (i = 0; i < l; i++) {
      if (s[i] == '?') s[i] = 'Z';
    }
    cout << s;
  }
  return 0;
}
