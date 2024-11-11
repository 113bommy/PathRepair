#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int INF = 2e9;
char s[maxn];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  queue<char> q;
  int idx1 = 1, idx2 = len, cnt, flag = 1;
  char c;
  while (idx1 < idx2) {
    if (s[idx1] != s[idx2]) {
      flag = 0;
      break;
    }
    c = s[idx1];
    cnt = 0;
    while (idx1 <= len && s[idx1] == c) {
      cnt++;
      idx1++;
    }
    while (idx2 > 0 && s[idx2] == c) {
      cnt++;
      idx2--;
    }
    if (idx1 < idx2) {
      if (cnt < 3) {
        flag = 0;
        break;
      }
    } else {
      cnt /= 2;
      if (cnt < 2) {
        flag = 0;
        break;
      }
    }
  }
  if (!flag)
    puts("0");
  else
    printf("%d\n", cnt + 1);
}
