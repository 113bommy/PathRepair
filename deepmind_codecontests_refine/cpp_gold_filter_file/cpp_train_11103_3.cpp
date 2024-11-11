#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'U' && s[i + 1] == 'R') {
      cnt++;
      i++;
    } else if (s[i] == 'R' && s[i + 1] == 'U') {
      cnt++;
      i++;
    }
  }
  printf("%d", n - cnt);
  return 0;
}
