#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100], t[100];
  cin.get(s, 100);
  cin.ignore(100, '\n');
  cin.get(t, 100);
  cin.ignore(100, '\n');
  int l1 = strlen(s);
  int l2 = strlen(t);
  int res = 0;
  int j = 0;
  for (int i = 0; i < l1; i++) {
    if (s[j] == t[i]) j++;
  }
  cout << j + 1 << endl;
  return 0;
}
