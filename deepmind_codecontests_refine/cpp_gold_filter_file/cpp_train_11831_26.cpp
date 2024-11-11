#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' ||
        s[i] == 'e' || s[i] == '1' || s[i] == '3' || s[i] == '5' ||
        s[i] == '7' || s[i] == '9')
      k++;
  cout << k;
  return 0;
}
