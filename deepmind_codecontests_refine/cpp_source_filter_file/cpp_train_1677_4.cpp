#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int j = 0, l = s.size() - 1;
  while (s[j] == s[j + 1] && j < s.size()) j++;
  if (s[l] == 'b' && l > 0)
    while (s[l] == s[l - 1]) l--;
  else
    l++;
  j++;
  for (int i = 0; i < j; i++) {
    printf("0 ");
  }
  for (int i = j; i < l; i++) {
    if (i == l - 1) {
      printf("1 ");
    } else if (s[i] == s[i + 1]) {
      printf("0 ");
    } else {
      printf("1 ");
    }
  }
  for (int i = l; i < s.size(); i++) {
    printf("0 ");
  }
}
