#include <bits/stdc++.h>
using namespace std;
int main() {
  int p;
  char s[1001];
  cin >> s;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == '.') p = i;
  if (s[p - 1] == '9') {
    cout << "GOTO Vasilisa.";
    return 0;
  }
  if (s[p + 1] >= 5) {
    s[p - 1]++;
    for (int i = 0; i < p; i++) cout << s[i];
    return 0;
  }
  for (int i = 0; i < p; i++) cout << s[i];
  return 0;
}
