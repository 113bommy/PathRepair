#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int main() {
  int i;
  cin.getline(s, 100001);
  cout << s;
  for (i = strlen(s) - 1; i >= 0; i--) cout << s[i];
  return 0;
}
