#include <bits/stdc++.h>
using namespace std;
int n, m, fs, sf;
string s, s2;
int main() {
  cin >> n;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '4' && s[i] != '7') {
      cout << "NO";
      return 0;
    }
    if (i >= n / 2)
      sum -= (s[i] - '0');
    else
      sum += (s[i] + '0');
  }
  if (sum != 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
