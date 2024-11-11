#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int count = 1, l = str.length();
  int i = l - 1;
  l--;
  while (i > 0) {
    if (str[i] == '0') {
      int zero = 0;
      while (str[i] == '0' && i > 0) i--, l--, zero++;
      if (l < zero + 1)
        break;
      else if (l == zero + 1) {
        int j = 0, f = 0;
        if (str[i] <= str[j])
          count++;
        else
          break;
      } else
        count++;
      i--;
      l--;
      continue;
    }
    if (l == 1) {
      if (str[i] < str[i - 1]) count++;
      i--;
      l--;
      continue;
    }
    count++;
    i--;
    l--;
  }
  cout << count << endl;
  return 0;
}
