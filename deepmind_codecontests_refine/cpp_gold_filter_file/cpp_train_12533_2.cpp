#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  long long int ans = 1;
  int a;
  scanf("%s", s);
  int n = strlen(s);
  map<char, bool> M;
  if (s[0] - '0' >= 0 && s[0] - '0' < 10) {
    a = 10;
    ans = 1;
  } else if (s[0] == '?') {
    a = 10;
    ans = 9;
  } else {
    a = 9;
    ans = 9;
    M[s[0]] = true;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '?')
      ans *= 10;
    else if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
      continue;
    else {
      if (!M[s[i]]) {
        M[s[i]] = true;
        ans *= a;
        a--;
      }
    }
  }
  cout << ans << endl;
}
