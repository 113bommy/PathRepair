#include <bits/stdc++.h>
using namespace std;
int n;
int a[250], b[5];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '!') a[s[i]] = i % 4;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '!') b[i % 4]++;
  }
  cout << b[a['R']] << " " << b[a['B']] << " " << b[a['Y']] << " " << b[a['G']]
       << endl;
}
