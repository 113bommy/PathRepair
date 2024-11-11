#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool poss = true;
  int c = 0;
  vector<int> ind;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '@') ind.push_back(i);
  if (ind.size() == 0) {
    puts("No solution");
    return 0;
  }
  if (ind[0] == 0 || ind[ind.size() - 1] == s.length() - 1)
    poss = false;
  else {
    for (int i = 1; i < ind.size(); i++)
      if (ind[i] - ind[i - 1] < 3) poss = false;
  }
  if (!poss)
    puts("No solution");
  else {
    cout << s[0];
    int i = 1;
    int c = 0;
    while (i < s.length()) {
      if (c != ind.size() - 1 && s[i] == '@') {
        cout << s[i] << s[i + 1] << ',';
        i += 2;
        c++;
      } else {
        cout << s[i];
        i++;
      }
    }
    cout << endl;
  }
  return 0;
}
