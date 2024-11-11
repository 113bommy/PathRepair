#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int w[26];
  for (int i = 0; i < 26; i++) {
    cin >> w[i];
  }
  int f = 0;
  for (int i = 0; i < s.length(); i++) {
    f = f + (i + 1) * w[s[i] - 'a'];
  }
  int mmax = w[0];
  for (int i = 0; i < 26; i++)
    if (w[i] > mmax) mmax = w[i];
  for (int i = s.length(); i < s.length() + 3; i++) f = f + (i + 1) * mmax;
  cout << f;
  return 0;
}
