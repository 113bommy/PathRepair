#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1, s2, s3;
  cin >> s >> s1 >> s2 >> s3;
  swap(s1[0], s1[1]);
  swap(s3[0], s3[1]);
  s = s + s1;
  s2 = s2 + s3;
  s.erase(s.find('X'), 1);
  s2.erase(s2.find('X'), 1);
  s += s;
  if (s.find(s2) != string::npos)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
