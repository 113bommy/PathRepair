#include <bits/stdc++.h>
using namespace std;
int n;
char s[103];
int main() {
  cin >> n;
  getchar();
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    int f = 0, r = 0, len = strlen(s);
    if (len >= 5 && s[len - 5] == 'l' && s[len - 4] == 'a' &&
        s[len - 3] == 'l' && s[len - 2] == 'a' && s[len - 1] == '.')
      f = 1;
    if (len >= 5 && s[0] == 'm' && s[1] == 'i' && s[2] == 'a' && s[3] == 'o' &&
        s[4] == '.')
      r = 1;
    if (f && !r)
      printf("Freda's\n");
    else if (!f && r)
      printf("Rainbow's\n");
    else
      printf("OMG>.< I don't know!\n");
  }
}
