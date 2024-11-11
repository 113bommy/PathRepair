#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 1;
  string s;
  bool flag = 0;
  cin >> n;
  cin >> s;
  if (n == 1 && s[0] == '0') {
    printf("NO\n");
    return 0;
  }
  if (n == 2) {
    if (s[0] != s[1]) {
      printf("YES\n");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt = 0;
      if (i == n - 1 && s[i - 1] == '1') {
        flag = 1;
        break;
      }
      if (i == 0 && s[i + 1] == '1') {
        flag = 1;
        break;
      }
      if (s[i - 1] == '1' || s[i + 1] == '1') {
        flag = 1;
        break;
      }
    } else
      cnt++;
    if (cnt > 2) {
      flag = 1;
      break;
    }
  }
  if (flag == 1 || cnt > 1)
    printf("NO\n");
  else
    printf("YES\n");
}
