#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a[256];
  for (int i = 0; i < 52; i++) a[i] = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - 'a' < 26 && s[i] - 'a' >= 0) {
      a[s[i] - 'a']++;
    } else {
      a[26 + s[i] - 'A']++;
    }
  }
  int min = a[27];
  if (min > a[0] / 2) min = a[0] / 2;
  if (min > a[1]) min = a[1];
  if (min > a[11]) min = a[11];
  if (min > a[17]) min = a[17];
  if (min > a[18]) min = a[18];
  if (min > a[20] / 2) min = a[20] / 2;
  cout << min << endl;
  return 0;
}
