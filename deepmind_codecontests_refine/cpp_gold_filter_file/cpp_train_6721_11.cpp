#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int len, count = 0, i;
  string str;
  cin >> len >> str;
  for (i = 0; i < len; ++i) {
    if (str[i] == '<')
      ++count;
    else
      break;
  }
  for (i = len - 1; i >= 0; --i) {
    if (str[i] == '>')
      ++count;
    else
      break;
  }
  cout << count << endl;
  return 0;
}
