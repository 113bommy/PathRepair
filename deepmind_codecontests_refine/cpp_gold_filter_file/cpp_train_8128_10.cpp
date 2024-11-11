#include <bits/stdc++.h>
using namespace std;
struct le {
  int num;
  char a;
};
int cmp(le x, le y) { return x.num < y.num; }
int main() {
  char str[100000] = {};
  int x;
  cin >> str >> x;
  le l[26] = {};
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    l[(int)str[i] - 97].num++;
    l[(int)str[i] - 97].a = str[i];
  }
  sort(l, l + 26, cmp);
  int temp = 0, i;
  for (i = 0; i < 26; i++) {
    if (l[i].num >= 0) {
      temp += l[i].num;
      if (temp <= x) {
        for (int j = 0; j < len; j++)
          if (str[j] == l[i].a) str[j] = '#';
      } else
        break;
    }
  }
  cout << 26 - i << endl;
  for (i = 0; i < len; i++)
    if (str[i] != '#') cout << str[i];
  return 0;
}
