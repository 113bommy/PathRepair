#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int t = 1;
  for (int i = 1; i < n; i++)
    if (s[i] == '0' && s[i - 1] != '0') {
      cout << t;
      t = 0;
    } else if (s[i] == '1')
      t++;
    else if (s[i] == '0')
      cout << "0";
  if (t) cout << t;
  return 0;
}
