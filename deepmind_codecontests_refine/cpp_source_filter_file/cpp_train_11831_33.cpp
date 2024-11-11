#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' ||
        s[i] == 'e' || s[i] == '2' || s[i] == '4' || s[i] == '6' ||
        s[i] == '8' || s[i] == '0')
      k++;
  cout << k;
  return 0;
}
