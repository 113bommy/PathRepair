#include <bits/stdc++.h>
using namespace std;
const int Maxn = 410;
;
char s[Maxn];
int cnt = 0, ans = 2;
int length = 0;
bool fs(int st, int n) {
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (s[st + i] == s[st + i + n] || s[st + i + n] == '1') {
      flag = true;
    } else {
      flag = false;
      break;
    }
  }
  if (flag) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int k = 0;
  cin >> s >> k;
  int n = 0;
  length = strlen(s);
  for (int i = 0; i < k; i++) {
    s[length + i] = '1';
  }
  length += k;
  n = length / 2;
  while (n) {
    for (int i = 0; i < length - n * 2 + 1; i++) {
      if (fs(i, n)) {
        ans = max(ans, n * 2);
      }
    }
    n--;
  }
  printf("%d\n", ans);
  return 0;
}
