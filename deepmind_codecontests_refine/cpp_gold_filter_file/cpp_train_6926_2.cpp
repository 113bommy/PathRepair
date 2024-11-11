#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    string s;
    cin >> s;
    s = s.substr(4);
    long long start = 1989;
    long long number = 1;
    for (int len = 1; len <= s.size(); len++) {
      string t = s.substr(s.size() - len);
      number *= 10;
      stringstream ss(t);
      long long x;
      ss >> x;
      if (x < number / 10) x += number;
      while (x < start) x += number;
      start = x + 1;
    }
    cout << start - 1 << endl;
  }
  return 0;
}
