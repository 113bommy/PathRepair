#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num;
  char s[100010];
  cin >> s;
  n = strlen(s);
  num = (int)(s[n - 2] - '0') * 10 + (int)(s[n - 1] - '0');
  if ((num % 4 == 0) || ((s[n - 2] == '0') && (s[n - 1] == 0)))
    cout << "4";
  else
    cout << "0";
  return 0;
}
