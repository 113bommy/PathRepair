#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, a, b, c, n, ar[10];
  char str[40], s1[8][5];
  cin >> n;
  for (k = 0; k < n; k++) {
    cin >> str;
    memset(s1, 0, sizeof(s1));
    memset(ar, 0, sizeof(ar));
    int len = strlen(str);
    int cnt = 0, nw = 0;
    for (i = 0; i < len; i++) {
      if (str[i] == ':' && str[i + 1] == ':') {
        ar[++cnt] = 1;
        continue;
      }
      if (str[i] == ':' && str[i + 1] != ':') {
        nw = 0;
        cnt++;
      } else
        s1[cnt][nw++] = str[i];
    }
    if (ar[0] == 1) {
      printf("0000:");
      for (j = 1; j < 7 - cnt; j++) printf(":0000");
    } else {
      len = strlen(s1[0]);
      for (j = 0; j < (4 - len); j++) printf("0");
      printf("%s", s1[0]);
    }
    for (i = 1; i <= cnt; i++) {
      if (ar[i] == 1) {
        for (j = 0; j < 8 - cnt - ar[0]; j++) printf(":0000");
        continue;
      }
      printf(":");
      len = strlen(s1[i]);
      for (j = 0; j < (4 - len); j++) printf("0");
      printf("%s", s1[i]);
    }
    cout << endl;
  }
}
