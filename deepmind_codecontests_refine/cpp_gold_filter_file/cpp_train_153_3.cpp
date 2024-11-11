#include <bits/stdc++.h>
using namespace std;
int a, b;
string s;
int main() {
  string s;
  int cnt = 0, i, j = 0, g;
  while (getline(cin, s)) {
    if (s[0] == '-')
      j--;
    else if (s[0] == '+')
      j++;
    else {
      i = 0;
      while (s[i] != ':') i++;
      cnt += (s.size() - i - 1) * j;
    }
  }
  cout << cnt;
  return 0;
}
