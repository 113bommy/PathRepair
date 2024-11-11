#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, h[1000] = {}, n, k, f = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    h[s[i] - 'a']++;
  }
  for (i = 0; i <= 26; i++) {
    if (h[i] != k && h[i] != 0) f = 1;
  }
  if (f)
    cout << "NO";
  else
    cout << "YES";
}
