#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i, j;
  char temp[] = "heidi";
  for (i = 0, j = 0; i < s.size(); i++) {
    if (s[i] == temp[j]) j++;
  }
  if (j == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
