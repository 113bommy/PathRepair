#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n-- > 0) {
    string s;
    cin >> s;
    long long sz = s.size();
    long long c_z = 0, c_o = 0;
    for (long long i = 0; s[i]; i++) {
      if (s[i] == '0')
        c_z++;
      else if (s[i] == '1')
        c_o++;
    }
    if (c_o == sz || c_z == sz)
      cout << s << "\n";
    else {
      for (long long i = 1; i <= 2 * sz; i++) {
        if (i & 1)
          cout << 0;
        else
          cout << 1;
      }
      cout << "\n";
    }
  }
}
