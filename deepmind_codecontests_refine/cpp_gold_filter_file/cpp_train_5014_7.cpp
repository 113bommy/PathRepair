#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string s;
  cin >> s;
  string a;
  long long i = 0, j = s.length() - 1;
  while ((j - i) >= 3) {
    if (s[i] == s[j]) {
      a.push_back(s[i]);
      i++;
      j--;
    } else if (s[i] == s[j - 1]) {
      a.push_back(s[i]);
      i++;
      j -= 2;
    } else {
      a.push_back(s[i + 1]);
      if (s[i + 1] == s[j]) {
        j--;
      } else
        j -= 2;
      i += 2;
    }
  }
  string b = a;
  if (j >= i) {
    a.push_back(s[i]);
  }
  reverse(b.begin(), b.end());
  cout << a << b << endl;
}
