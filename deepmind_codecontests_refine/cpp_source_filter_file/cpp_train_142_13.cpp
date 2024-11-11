#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length(), a[3] = {0};
  for (int i = 0; i < l; i++) {
    if (s[i] == '1') {
      a[0]++;
      i++;
    } else if (s[i] == '2') {
      a[1]++;
      i++;
    } else if (s[i] == '3') {
      a[2]++;
      i++;
    }
  }
  for (int i = 0; i < 3; i++) {
    while (a[i] > 0) {
      cout << i + 1;
      l--;
      if (l > 0) cout << "+";
      a[i]--;
    }
  }
  return 0;
}
