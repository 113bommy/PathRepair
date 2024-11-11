#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
int main() {
  int n;
  string s;
  cin >> n >> s;
  map<char, int> mm;
  if (n % 4) {
    cout << "===" << endl;
    return 0;
  } else
    n /= 4;
  for (int i = 0; i <= s.length() - 1; i++) mm[s[i]]++;
  for (int i = 0; i <= s.length() - 1; i++)
    if (s[i] == '?') {
      if (mm['A'] < n)
        s[i] = 'A', mm['A']++;
      else if (mm['C'] < n)
        s[i] = 'C', mm['C']++;
      else if (mm['G'] < n)
        s[i] = 'G', mm['G']++;
      else if (mm['T'] < n)
        s[i] = 'T', mm['T']++;
    }
  if (mm['A'] == n && mm['C'] == n && mm['G'] == n && mm['T'] == n)
    cout << s << endl;
  else
    cout << "===" << endl;
  return 0;
}
