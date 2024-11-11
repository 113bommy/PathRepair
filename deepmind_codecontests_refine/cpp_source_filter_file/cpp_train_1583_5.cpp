#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  bool prime[s.length() + 1];
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  set<int> v;
  for (int i = 2; i <= s.length(); i++) {
    int j = 2 * i, flag = 0;
    while (j <= s.length()) {
      prime[j] = false;
      v.insert(j);
      j += j;
      flag = 1;
    }
    if (flag == 1) v.insert(i);
  }
  int a[26], ind = -1;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < s.length(); i++) a[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (a[i] >= v.size()) {
      ind = i;
      break;
    }
  }
  if (ind == -1)
    cout << "NO\n";
  else {
    cout << "YES\n";
    char h[s.length()];
    memset(h, '#', sizeof(h));
    for (auto it = v.begin(); it != v.end(); it++) h[(*it) - 1] = ind + 'a';
    a[ind] -= v.size();
    ind = 0;
    for (int i = 0; i < s.length(); i++) {
      if (h[i] == '#') {
        while (a[ind] == 0 && ind < 26) ind++;
        if (ind >= 26) break;
        h[i] = ind + 'a';
        a[ind]--;
      }
    }
    for (int i = 0; i < s.length(); i++) cout << h[i];
    cout << "\n";
  }
  return 0;
}
