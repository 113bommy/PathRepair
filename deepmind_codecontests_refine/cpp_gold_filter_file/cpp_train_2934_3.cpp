#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
  cin >> s;
  int cnt = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0')
      cnt++;
    else if (cnt)
      cnt--;
    else
      s[i] = '0';
  }
  cout << s;
  return 0;
}
