#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int n, p;
char str[1005];
bool is_plaindom(int i, int j) {
  int mid = (i + j) >> 1;
  int l = i;
  int h = j;
  for (; l <= mid; l++, h--)
    if (str[l] != str[h]) return 0;
  return true;
}
int main() {
  while (scanf("%d %d", &n, &p) == 2) {
    int flag = 0;
    scanf("%s", str);
    int len = strlen(str);
    string tmp = "", ans = "";
    int pos;
    char a, b, ch;
    for (int i = len - 1; i >= 0; i--) {
      for (int j = int(str[i]) + 1; j < 'a' + p; j++) {
        ch = char(j);
        if (str[i - 1] != ch && str[i - 2] != ch) {
          flag = 1;
          tmp += ch;
          pos = i;
          for (int k = 'a'; k < 'a' + p; k++) {
            if (i < 1 && ch != k) {
              b = k;
              break;
            } else if (str[i - 1] > char(k) && ch != k) {
              b = k;
              break;
            }
          }
          for (int k = 0; k < i; k++) {
            printf("%c", str[k]);
          }
          printf("%c", ch);
          break;
        }
      }
      if (flag) break;
    }
    if (!flag)
      printf("NO\n");
    else {
      int cnt = 0;
      if (pos + 1 < len) printf("%c", b);
      pos++;
      for (int i = pos + 1; i < len; i++) {
        char now = 'a';
        while (now == b || now == ch) {
          now++;
          if (now >= 'a' + p) now = 'a';
        }
        ch = b;
        b = now;
        printf("%c", now);
      }
      printf("\n");
    }
  }
  return 0;
}
