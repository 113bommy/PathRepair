#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, sm = 0, nu = 0, la = 0;
  char s[1000];
  cin >> s;
  n = strlen(s);
  for (i = 0; i < strlen(s); i++) {
    if (s[i] <= 90 && s[i] >= 65) sm++;
    if (s[i] <= 122 && s[i] >= 96) la++;
    if (s[i] <= 57 && s[i] >= 48) nu++;
  }
  if (sm > 0 && la > 0 && nu > 0)
    cout << "Correct";
  else
    cout << "Too weak";
}
