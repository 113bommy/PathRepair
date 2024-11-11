#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int h = 0;
  int t = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) == 'H')
      h++;
    else
      t++;
  }
  int cou = 0;
  for (int i = 0; i < t; i++) {
    if (s.at(i) == 'H') cou++;
  }
  int mini = cou;
  for (int i = 1; i <= s.length() - t; i++) {
    if (s.at(i - 1) == 'H') cou--;
    if (s.at(i + t - 1) == 'H') cou++;
    mini = min(mini, cou);
  }
  int co = 0;
  for (int i = 0; i < h; i++) {
    if (s.at(i) == 'T') cou++;
  }
  mini = min(co, mini);
  for (int i = 1; i <= s.length() - h; i++) {
    if (s.at(i - 1) == 'T') co--;
    if (s.at(i + t - 1) == 'T') co++;
    mini = min(mini, co);
  }
  cout << mini << endl;
  return 0;
}
