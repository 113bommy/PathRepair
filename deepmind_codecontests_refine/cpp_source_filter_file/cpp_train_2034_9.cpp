#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long h = 0;
  if (s[0] == '-') h = 1;
  if (s[0] == '-') s.erase(s.begin());
  string b = "127", i = "2147483648", sh = "32768", l = "9223372036854775808";
  if (h) {
    if ((s < "129" and s.size() == b.size()) or s.size() < b.size()) {
      cout << "byte";
      return 0;
    }
    if (s < "32769" and s.size() == sh.size() or s.size() < sh.size()) {
      cout << "short";
      return 0;
    }
    if (s < "2147483649" and s.size() == i.size() or s.size() < i.size()) {
      cout << "int";
      return 0;
    }
    if (s < "9223372036854775809" and s.size() == l.size() or
        s.size() < l.size()) {
      cout << "long";
      return 0;
    }
    cout << "BigInteger";
    return 0;
  }
  if (s < b and s.size() == 3 or s.size() < b.size()) {
    cout << "byte";
    return 0;
  }
  if (s < sh and s.size() == 5 or s.size() < sh.size()) {
    cout << "short";
    return 0;
  }
  if (s < i and s.size() == i.size() or s.size() < i.size()) {
    cout << "int";
    return 0;
  }
  if (s < l and s.size() == l.size() or s.size() < i.size()) {
    cout << "long";
    return 0;
  }
  cout << "BigInteger";
  return 0;
}
