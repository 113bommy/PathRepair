#include <bits/stdc++.h>
using namespace std;
char p[6][10] = {"lios", "liala", "etr", "etra", "initis", "inites"};
int q[100010];
int main() {
  char s[100010];
  bool flag = 0;
  int cnt = 0;
  while (cin >> s) {
    bool falg = 0;
    for (int i = 0; i < 6; i++)
      if (strlen(p[i]) < strlen(s)) {
        if (!strcmp(p[i], s + strlen(s) - strlen(p[i]))) {
          falg = 1;
          q[cnt] = i;
        }
      }
    if (!falg) {
      flag = 1;
      break;
    }
    cnt++;
  }
  if (flag)
    cout << "NO\n";
  else {
    if (cnt == 1) {
      cout << "YES\n";
      return 0;
    }
    int sd = q[0] % 2;
    for (int i = 1; i < cnt; i++)
      if (sd != q[i] % 2) {
        cout << "NO\n";
        return 0;
      }
    int ppp = 0;
    if (q[0] / 2 == 1) ppp = 1;
    for (int i = 1; i < cnt; i++) {
      if (q[i] / 2 == 1) ppp++;
      if (q[i] < q[i - 1]) {
        cout << "NO\n";
        return 0;
      }
    }
    if (ppp != 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
