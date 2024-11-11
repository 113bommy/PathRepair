#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt;
  cin >> n;
  string s;
  cin >> s;
  cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1')
      cnt++;
    else
      cout << cnt, cnt = 0;
  }
  cout << cnt << endl;
  return 0;
}
