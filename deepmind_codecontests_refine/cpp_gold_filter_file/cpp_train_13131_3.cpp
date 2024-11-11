#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
vector<int> groups;
long long a, b;
string s1, s2;
string toLower(string s) {
  string result = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 97)
      result += (char)(s[i] + 32);
    else
      result += s[i];
  }
  return result;
}
int main() {
  cin >> s1 >> s2;
  s1 = toLower(s1);
  s2 = toLower(s2);
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] < s2[i]) {
      cout << -1;
      return 0;
    }
    if (s1[i] > s2[i]) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
