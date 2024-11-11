#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[1005];
  scanf("%s", s);
  int o = 0, l = 0;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == '-')
      l++;
    else
      o++;
  if (o == 0 || o == 1 || l == 0 || l % o == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
