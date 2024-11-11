#include <bits/stdc++.h>
using namespace std;
char s[1000010];
string out;
string judge;
char pp[1000010];
int qq;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    gets(s);
    bool flag = false;
    int cnt = 0;
    int mm;
    out = "Unhandled Exception";
    for (int i = 0; i < n; i++) {
      gets(s);
      if (out != "Unhandled Exception") continue;
      int len = strlen(s);
      int st = len;
      for (int i = 0; i < len; i++)
        if (s[i] != ' ') {
          st = i;
          break;
        }
      if (st == len) continue;
      if (len == 0)
        continue;
      else if (s[st] == 't' && s[st + 1] == 'r' && s[st + 2] == 'y') {
        st += 3;
        cnt++;
      } else if (s[st] == 't' && s[st + 1] == 'h' && s[st + 2] == 'r' &&
                 s[st + 3] == 'o' && s[st + 4] == 'w') {
        mm = cnt;
        st += 5;
        flag = true;
        for (int i = st; i < len; i++)
          if (s[i] == '(') {
            st = i + 1;
            break;
          }
        for (int i = st; i < len; i++)
          if (s[i] != ' ') {
            st = i;
            break;
          }
        judge = "";
        for (int i = st; i < len; i++) {
          if (s[i] == ' ' || s[i] == ')') break;
          judge += s[i];
        }
      } else {
        cnt--;
        if (!flag) continue;
        if (cnt >= mm) continue;
        mm = cnt;
        st += 5;
        for (int i = st; i < len; i++)
          if (s[i] == '(') {
            st = i + 1;
            break;
          }
        for (int i = st; i < len; i++)
          if (s[i] != ' ') {
            st = i;
            break;
          }
        string now = "";
        for (int i = st; i < len; i++) {
          if (s[i] == ' ' || s[i] == ',') break;
          now += s[i];
        }
        if (judge == now) {
          for (int i = st; i < len; i++)
            if (s[i] == '"') {
              st = i + 1;
              break;
            }
          out = "";
          for (int i = st; i < len; i++) {
            if (s[i] == '"') break;
            out += s[i];
          }
        }
      }
    }
    cout << out << endl;
  }
  return 0;
}
