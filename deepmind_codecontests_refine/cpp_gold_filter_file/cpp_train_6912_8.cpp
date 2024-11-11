#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  char s[10000];
  getchar();
  scanf("%s", s);
  int num = 0, ans = 0;
  for (int i = 1; s[i]; i++) {
    if (i % n == 0) {
      if (num >= 3) {
        ans++;
      }
      num = 0;
    } else {
      if (s[i] == s[i - 1]) {
        num++;
      } else {
        num = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
