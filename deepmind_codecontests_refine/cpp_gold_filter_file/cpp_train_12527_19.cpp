#include <bits/stdc++.h>
using namespace std;
char s[400009];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool ok = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '.') {
      ok = 1;
      break;
    }
  if (!ok) {
    printf("NO");
    return 0;
  }
  int cnt = 0;
  int L, R;
  for (int i = 0; s[i] != '.'; i++) {
    cnt++;
  }
  L = cnt;
  if (cnt < 1 || cnt > 8) {
    printf("NO");
    return 0;
  }
  cnt = 0;
  for (int i = n - 1; s[i] != '.'; i--) {
    cnt++;
  }
  R = n - 1 - cnt;
  if (cnt < 1 || cnt > 3) {
    printf("NO");
    return 0;
  }
  cnt = 0;
  for (int i = L + 1; i <= R; i++) {
    if (s[i] == '.') {
      if (cnt < 2 || cnt > 11) {
        printf("NO");
        return 0;
      }
      cnt = 0;
    } else
      cnt++;
  }
  printf("YES\n");
  for (int i = 0; i <= L; i++) printf("%c", s[i]);
  cnt = 0;
  int from = L + 1;
  for (int i = L + 1; i <= R; i++) {
    if (s[i] == '.') {
      if (cnt > 3) {
        for (int j = from; j < from + 3; j++) printf("%c", s[j]);
        printf("\n");
        for (int j = from + 3; j <= i; j++) printf("%c", s[j]);
      } else {
        printf("%c\n", s[from]);
        for (int j = from + 1; j <= i; j++) printf("%c", s[j]);
      }
      from = i + 1;
      cnt = 0;
    } else
      cnt++;
  }
  for (int i = R + 1; i < n; i++) printf("%c", s[i]);
}
