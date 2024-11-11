#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int co = 0;
  for (long long i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) {
      co++;
      if (co >= 6) break;
    } else {
      co = 0;
    }
  }
  if (co >= 6)
    cout << "Yes";
  else
    cout << "No";
}
