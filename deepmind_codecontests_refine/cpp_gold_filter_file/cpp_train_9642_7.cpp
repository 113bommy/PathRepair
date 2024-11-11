#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sf = 0;
  int fs = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'F' && s[i - 1] == 'S') sf++;
    if (s[i] == 'S' && s[i - 1] == 'F') fs++;
  }
  if (sf > fs)
    cout << "Yes";
  else
    cout << "No";
}
