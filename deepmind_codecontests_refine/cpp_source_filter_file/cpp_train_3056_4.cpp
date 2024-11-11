#include <bits/stdc++.h>
const int maxn = 1e5;
using namespace std;
char s[maxn];
int dd[maxn];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i <= len - 2; i++)
    if (s[i] == '/' && s[i + 1] == '/') dd[i] = 1;
  for (int i = len - 1; i >= 1; i--) {
    if (s[i] != '/') break;
    dd[i] = 1;
  }
  for (int i = 0; i <= len - 1; i++)
    if (dd[i] == 0) cout << s[i];
  return 0;
}
