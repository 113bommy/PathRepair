#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
  cin >> s1 >> s2;
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < s1.size(); ++i)
    if (s1[i] == '1') ++p1;
  for (int i = 0; i < s2.size(); ++i)
    if (s2[i] == '1') ++p2;
  if (p1 + p1 % 2 >= p2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
