#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int prea[s.size() + 1], preb[s.size() + 1];
  prea[0] = 0;
  preb[0] = 0;
  for (int i = 1; i < s.size() + 1; i++) {
    if (s[i - 1] == 'a')
      prea[i] = prea[i - 1] + 1;
    else
      prea[i] = prea[i - 1];
  }
  for (int i = 1; i < s.size() + 1; i++) {
    if (s[i - 1] == 'b')
      preb[i] = preb[i - 1] + 1;
    else
      preb[i] = preb[i - 1];
  }
  int maxl = 0;
  for (int i = 0; i < s.size(); i++)
    for (int j = i; j < s.size(); j++) {
      int temp = prea[i] + (preb[j] - preb[i]) + (prea[s.size()] - prea[j]);
      maxl = max(maxl, temp);
    }
  cout << maxl << endl;
}
