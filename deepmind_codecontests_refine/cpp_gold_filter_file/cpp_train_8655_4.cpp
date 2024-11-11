#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i, c = 0;
  int len = s.size();
  for (i = 0; i < len; i++)
    if (s[i] == 'a') c++;
  if (c > (len + 1) / 2)
    cout << len << endl;
  else
    cout << c + c - 1 << endl;
}
