#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    long long int sz = s.size(), one = 0, zero = 0;
    for (i = 0; i < sz; i++) {
      if (s[i] == '1')
        one++;
      else
        zero++;
    }
    if (sz <= 2 || one == sz || zero == sz)
      cout << s << '\n';
    else {
      s.push_back('#');
      for (i = 0; i < sz; i++) {
        cout << s[i];
        if (s[i] == '0' && s[i + 1] == '0')
          cout << 0;
        else if (s[i] == '1' && s[i + 1] == '1')
          cout << 0;
      }
      cout << '\n';
    }
  }
  return 0;
}
