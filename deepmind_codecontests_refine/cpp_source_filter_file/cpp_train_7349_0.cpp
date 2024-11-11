#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int MAXIOSIZE = 1 << 24 | 1;
unsigned char buf[MAXIOSIZE], *p1, *p2;
template <typename T>
void read(T& x) {
  x = 0;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
           ? EOF
           : *p1++);
  bool flg = false;
  for (; ch < '0' || '9' < ch;
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') flg |= true;
  for (; '0' <= ch && ch <= '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 24, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    x = x * 10 + ch - '0';
  flg ? x = -x : 0;
}
template <typename T>
void out(const T& x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void write(const T& x, const char& ed = ' ') {
  if (x < 0)
    putchar('-'), out(-x);
  else
    out(x);
  putchar(ed);
}
}  // namespace IO
const int MAXN = 256 + 10;
string str;
int main() {
  getline(cin, str);
  int prepos = -1;
  bool all_space = false;
  for (int i = 0; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      if (all_space && prepos != -1 && !isdigit(str[i - 1]))
        str.insert(i, 1, '@'), ++i;
      all_space = true, prepos = i;
    } else
      all_space &= (str[i] == ' ');
  }
  while (str.find(' ') != string::npos) {
    str.erase(str.find(' '), 1);
  }
  int sscnt = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '.')
      sscnt++;
    else
      sscnt = 0;
    if (sscnt == 3 && i == 2) sscnt = 0;
    if (sscnt == 3 && i > 2) {
      sscnt = -1;
      str.insert(i - 2, 1, ' ');
    }
    if (i < str.size() - 1 && str[i] == ',' && str[i + 1] != ' ')
      str.insert(i + 1, 1, ' ');
  }
  for (int i = 0; i < str.size(); ++i)
    if (str[i] == '@') str[i] = ' ';
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != ' ') continue;
    int j = i + 1;
    while (j < str.size() && str[j] == ' ') ++j;
    str.erase(i + 1, j - i - 1);
    if (j - i - 1 > 0) i = 0;
  }
  cout << str << '@';
  return 0;
}
