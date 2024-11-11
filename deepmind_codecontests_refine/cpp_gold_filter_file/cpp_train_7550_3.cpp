#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  k = 0;
  cin >> n >> s;
  int a[26];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] > 1) {
      k += (a[i] - 1);
    }
  }
  if (n > 26)
    cout << -1 << endl;
  else
    cout << k << endl;
  return 0;
}
