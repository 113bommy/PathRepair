#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n--) {
    string s, s1, res;
    cin >> s;
    long long k = s.size();
    if (k > 10) {
      s1 = to_string(k - 2);
      res = s[0] + s1 + s[k - 1];
      cout << res << endl;
    } else
      cout << s << endl;
  }
}
