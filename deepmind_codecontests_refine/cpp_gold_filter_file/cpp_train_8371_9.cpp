#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  int j = i + 1;
  int count = 0;
  int req = 0;
  if (s.length() == 1) {
    cout << 0;
    return 0;
  }
  while (i < s.length()) {
    while (j <= s.length()) {
      if (s[i] == s[j]) {
        i++;
        j++;
        count++;
      } else {
        i++;
        j++;
        count++;
        if (count % 2 == 0) req++;
        count = 0;
      }
    }
  }
  cout << req;
  return 0;
}
