#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1, s2, s3, s4, s5;
  bool b = false;
  cin >> s >> s1 >> s2 >> s3 >> s4 >> s5;
  if (s.front() == s1.front() || s.front() == s2.front() ||
      s.front() == s3.front() || s.front() == s4.front() ||
      s.front() == s5.front())
    b = true;
  if (s.back() == s1.back() || s.back() == s2.back() || s.back() == s3.back() ||
      s.back() == s4.back() || s.back() == s5.back())
    b = true;
  if (b == true) {
    cout << "YES";
  } else
    cout << "NO";
}
