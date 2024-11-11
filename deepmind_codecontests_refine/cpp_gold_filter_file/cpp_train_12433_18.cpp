#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long nn, long long pp, long long mm) {
  long long res = 1;
  while (pp > 0) {
    if (pp & 1) res = (res * nn) % mm;
    pp = pp >> 1;
    nn = (nn * nn) % mm;
  }
  return res;
}
void dhimanda();
int o = 0, x = 0, dot = 0;
void win(string s) {
  if (s[0] == 'X') {
    if (x - o == 1)
      puts("the first player won");
    else
      puts("illegal");
  } else {
    if (x == o)
      puts("the second player won");
    else
      puts("illegal");
  }
}
void test(string s) {
  std::map<char, int> map;
  map.clear();
  for (char i : s) {
    map[i]++;
  }
  if (map.size() > 1)
    puts("illegal");
  else
    win(s);
}
string ren(char ch) {
  if (ch == 'X')
    return "X";
  else if (ch == '0')
    return "0";
  else
    return "";
}
string game(char a[3][3]) {
  string s = "";
  if (a[0][0] == a[0][1] and a[0][1] == a[0][2]) s += ren(a[0][0]);
  if (a[0][0] == a[1][0] and a[1][0] == a[2][0]) s += ren(a[0][0]);
  if (a[0][0] == a[1][1] and a[1][1] == a[2][2]) s += ren(a[0][0]);
  if (a[0][1] == a[1][1] and a[1][1] == a[2][1]) s += ren(a[0][1]);
  if (a[0][2] == a[1][2] and a[1][2] == a[2][2]) s += ren(a[0][2]);
  if (a[1][0] == a[1][1] and a[1][1] == a[1][2]) s += ren(a[1][0]);
  if (a[2][0] == a[2][1] and a[2][1] == a[2][2]) s += ren(a[2][0]);
  if (a[2][0] == a[2][1] and a[2][1] == a[2][2]) s += ren(a[2][0]);
  if (a[0][2] == a[1][1] and a[1][1] == a[2][0]) s += ren(a[0][2]);
  return s;
}
int main() {
  char a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < int(3); i++)
    for (int j = 0; j < int(3); j++) {
      if (a[i][j] == 'X')
        x++;
      else if (a[i][j] == '0')
        o++;
      else
        dot++;
    }
  if (abs(o - x) > 1 or o > x)
    puts("illegal");
  else {
    string s = game(a);
    if (s.size() > 1) test(s);
    if (s.size() == 1)
      win(s);
    else if (s.size() == 0) {
      if (dot == 0)
        puts("draw");
      else
        cout << (x > o ? "second" : "first") << '\n';
    }
  }
  return 0;
}
