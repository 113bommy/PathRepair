#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, answer = 1;
  string s;
  cin >> s;
  char tmp = s[0];
  i = 1;
  j = 1;
  while (i < s.size()) {
    if (s[i] != tmp) {
      answer++;
      tmp = s[i];
      j = 1;
    } else if (j < 5) {
      j++;
    } else {
      answer++;
      j = 0;
    }
    i++;
  }
  cout << answer;
  return 0;
}
