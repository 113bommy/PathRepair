#include <bits/stdc++.h>
using namespace std;
int n, p;
char s[1024];
int main() {
  cin >> n >> p;
  cin >> s;
  int n = strlen(s);
  for (int i = n - 1; i >= 0; i--) {
    for (char ch = s[i] + 1; ch <= 'z' and ch < 'a' + p; ch++) {
      if (i > 0 and ch == s[i - 1]) continue;
      if (i > 1 and ch == s[i - 2]) continue;
      if (p == 1 and n > 1) continue;
      if (p == 2 and n > 2) continue;
      for (int j = 0; j < i; j++) putchar(s[j]);
      s[i] = ch;
      putchar(s[i]);
      for (int j = i + 1; j < n; j++) {
        for (char ch = 'a'; ch <= 'z' and ch < 'a' + p; ch++) {
          if (i > 0 and ch == s[j - 1]) continue;
          if (i > 1 and ch == s[j - 2]) continue;
          s[j] = ch;
          break;
        }
        putchar(s[j]);
      }
      putchar('\n');
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}
