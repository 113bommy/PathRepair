#include <bits/stdc++.h>
using namespace std;
int main() {
  set<char> yes, no;
  int n;
  char type, temp;
  char s[100010];
  scanf("%d", &n);
  int flag = 0, cnt = 0;
  scanf("%c", &temp);
  while (n--) {
    if (yes.size() == 1 || no.size() == 25) flag = 1;
    scanf("%c", &type);
    scanf("%c", &temp);
    scanf("%s", s);
    scanf("%c", &temp);
    int nn = strlen(s);
    if (n != 0) {
      if (flag == 1) {
        if ((type == '?' || type == '!')) cnt++;
        continue;
      }
      if (type == '?') {
        if (yes.find(s[0]) != yes.end()) {
          yes.erase(s[0]);
        }
        no.insert(s[0]);
      }
      if (type == '.') {
        for (int i = 0; i < nn; i++) {
          if (yes.find(s[i]) != yes.end()) {
            yes.erase(s[i]);
          }
          no.insert(s[i]);
        }
      }
      if (type == '!' && yes.size() != 0) {
        set<char> yestemp;
        for (int i = 0; i < nn; i++) {
          yestemp.insert(s[i]);
        }
        for (set<char>::iterator it = yes.begin(); it != yes.end();) {
          if (yestemp.find(*it) == yestemp.end()) {
            char it2 = *it;
            it++;
            yes.erase(it2);
            no.insert(it2);
          } else
            it++;
        }
      }
      if (type == '!' && yes.size() == 0) {
        for (int i = 0; i < nn; i++) {
          if (no.find(s[i]) == no.end()) yes.insert(s[i]);
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
