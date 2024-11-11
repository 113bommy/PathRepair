#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream inf("input.txt");
  string s, s1;
  cin >> s;
  int l = s.size(), j;
  for (int i = 0; i <= l - 1; i++)
    if (s[i] == '|') j = i;
  cin >> s1;
  int l1 = s1.size();
  if (l1 < abs(j - (l - j - 1)) || (l1 - abs(j - (l - j - 1))) % 2 == 1) {
    cout << "Impossible";
    return 0;
  }
  int h = (j + (l - j - 1) + l1) / 2;
  for (int i = 0; i <= j - 1; i++) cout << s[i];
  int g = 0;
  for (int i = j; i <= h - 1; i++) {
    cout << s1[g];
    g++;
  }
  cout << '|';
  for (int i = j + 1; i <= l - 1; i++) cout << s[i];
  for (int i = g; i <= l1 - 1; i++) cout << s1[i];
}
