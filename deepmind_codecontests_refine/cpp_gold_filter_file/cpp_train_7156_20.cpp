#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[105];
  cin >> s + 1;
  int n = strlen(s + 1);
  bool ans = 0;
  for (int i = 1; i <= n; i++)
    if (isalpha(s[i]) && isalpha(s[i - 1]) && isalpha(s[i + 1]) &&
        s[i] != s[i - 1] && s[i] != s[i + 1] && s[i - 1] != s[i + 1])
      ans = 1;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
