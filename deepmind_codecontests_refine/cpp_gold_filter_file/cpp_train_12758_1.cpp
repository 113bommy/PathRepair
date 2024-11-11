#include <bits/stdc++.h>
using namespace std;
int main() {
  bool first = 0;
  string str;
  cin >> str;
  int n = str.size();
  for (int i = 0; i < n; ++i)
    if (str[i] != 'a') {
      --str[i];
      first = 1;
    } else if (first)
      break;
  if (!first) str[n - 1] = 'z';
  cout << str;
}
