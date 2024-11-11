#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int pos = s.find('.'), pos1 = s.find('e'), cnt = 0, len = s.size();
  if (s[pos - 1] == '0') {
    if (s[pos + 1] == '0' && s[pos + 2] == 'e') {
      cout << 0 << endl;
      return 0;
    }
    printf("0.");
    for (int i = pos + 1; i < pos1; i++) {
      printf("%c", s[i]);
    }
    printf("\n");
  } else {
    int num = 0, step = 0;
    for (int i = len - 1;; i--) {
      if (s[i] == 'e') break;
      num += (s[i] - '0') * pow(10, step);
      step++;
    }
    if (num == 0 && s[pos + 1] == '0' && pos1 - 1 == pos) {
      cout << s[0] << endl;
      return 0;
    }
    int cha = pos1 - pos - 1;
    if (cha > num) {
      for (int i = 0; i < pos; i++) {
        printf("%c", s[i]);
      }
      char op;
      int f = pos;
      for (int i = pos + 1; i < pos + 1 + num; i++) {
        printf("%c", s[i]);
        op = s[i - 1];
        s[i - 1] = s[i];
        s[i] = op;
        f++;
      }
      printf(".");
      for (int i = f; i < pos1; i++) {
        if (s[i] != '.') printf("%c", s[i]);
      }
      printf("\n");
    } else if (cha == num) {
      for (int i = 0; i < pos1; i++) {
        if (s[i] != '.') printf("%c", s[i]);
      }
      printf("\n");
    } else if (cha < num) {
      for (int i = 0; i < pos1; i++) {
        if (s[i] != '.') printf("%c", s[i]);
      }
      for (int i = 0; i < num - cha; i++) {
        printf("0");
      }
      printf("\n");
    }
  }
  return 0;
}
