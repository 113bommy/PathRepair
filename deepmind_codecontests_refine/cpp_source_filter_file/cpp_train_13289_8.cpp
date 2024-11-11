#include <bits/stdc++.h>
using namespace std;
string s;
char res[100010];
int len;
int func(int cur, int n4, int n7, int prev) {
  if (cur == len) {
    for (int i = (0), _n = (len); i < _n; i++) printf("%c", res[i]);
    cout << endl;
    return 1;
  } else {
    if (prev) {
      if (n4) {
        res[cur] = '4';
        return func(cur + 1, n4 - 1, n7, 1);
      }
      res[cur] = '7';
      return func(cur + 1, n4, n7 - 1, 1);
    } else {
      if (s[cur] <= '4' && n4) {
        res[cur] = '4';
        int flag = 0;
        if (s[cur] < '4') flag = 1;
        int val = func(cur + 1, n4 - 1, n7, flag);
        if (val) return 1;
      }
      if (s[cur] <= '7' && n7) {
        res[cur] = '7';
        int flag = 0;
        if (s[cur] < '7') flag = 1;
        int val = func(cur + 1, n4, n7 - 1, flag);
        if (val) return 1;
      }
    }
  }
  return 0;
}
int main() {
  cin >> s;
  len = s.size();
  if (len % 2 == 1) {
    len++;
    for (int i = (0), _n = (len / 2); i < _n; i++) printf("4");
    for (int i = (0), _n = (len / 2); i < _n; i++) printf("7");
    cout << endl;
    return 0;
  } else {
    int n4 = len / 2;
    int n7 = len / 2;
    int val = func(0, n4, n7, 0);
    if (!val) {
      len++;
      for (int i = (0), _n = (len / 2); i < _n; i++) printf("4");
      for (int i = (0), _n = (len / 2); i < _n; i++) printf("7");
      cout << endl;
      return 0;
    }
  }
  return 0;
}
