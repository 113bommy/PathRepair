#include <bits/stdc++.h>
using namespace std;
int main() {
  int j = 0;
  string s, s1 = "heidi";
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == s1[j]) j++;
    if (j == 5) break;
  }
  if (j == 5)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
