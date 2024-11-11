#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int m[259] = {};
  for (int i = 0; i < s.length(); i++) m[s[i]]++;
  int kb = 0;
  multiset<int> se;
  int mini = INT_MAX;
  for (int i = 0; i < 256; i++) {
    if (m[i] != 0) {
      kb++;
      if (m[i] < mini) mini = m[i];
      se.insert(m[i]);
    }
  }
  if (kb > 4)
    cout << "No";
  else if (kb == 4)
    cout << "Yes";
  else if (kb == 3 && s.length() >= 4)
    cout << "Yes";
  else if (kb == 2 && mini >= 2)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
