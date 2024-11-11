#include <bits/stdc++.h>
using namespace std;
int main() {
  bool a[91];
  memset(a, false, sizeof a);
  a[65] = true;
  a[72] = true;
  a[73] = true;
  a[77] = true;
  a[79] = true;
  a[84] = true;
  a[85] = true;
  a[86] = true;
  a[87] = true;
  a[88] = true;
  a[89] = true;
  char s[100000];
  scanf("%s", &s);
  int len = strlen(s);
  bool isMirror = true;
  for (int i = 0; i < len / 2 + 1; i++) {
    if (s[i] != s[len - i - 1] || a[s[i]] == false) {
      isMirror = false;
      break;
    }
  }
  if (isMirror == true) {
    printf("YES");
  } else {
    printf("NO");
  }
}
