#include <bits/stdc++.h>
using namespace std;
char s[100005];
int id(char ch) {
  if (ch <= '9' && ch >= '0') return ch - '0';
  if (ch <= 'Z' && ch >= 'A') return ch - 'A' + 10;
  if (ch >= 'a' && ch <= 'z') return ch - 'a' + 36;
  if (ch == '-') return 62;
  if (ch == '_') return 63;
}
int main() {
  scanf("%s", s);
  int ans = 1;
  unsigned long len = strlen(s);
  for (int i = 0; i < len; i++) {
    int p = id(s[i]);
    for (int j = 0; j < 6; j++) {
      if (!((p >> j) & 1)) ans = ans * 3 % 1000000007;
    }
  }
  cout << ans << endl;
}
