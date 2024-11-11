#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  string s;
  scanf("%d", &n);
  ;
  cin >> s;
  for (int i = n; i < s.size(); i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) c++;
  }
  printf("%d\n", c);
  return 0;
}
