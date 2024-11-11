#include <bits/stdc++.h>
using namespace std;
char rev(char c) {
  if (c == 'l') return 'r';
  if (c == 'r') return 'l';
  if (c == 'u') return 'd';
  if (c == 'd') return 'u';
  assert(0);
  return 'x';
}
void if0(int c) { printf("%c%ct", c, rev(c)); }
void if1(int c) { printf("%c%cst", c, rev(c)); }
void ife(int c) { printf("%cs%ct%c", rev(c), c, c); }
void ifn0(int c) { printf("%c%ct%c", rev(c), c, c); }
void ifn1(int c) { printf("%c%cst%c", rev(c), c, c); }
void ifne(int c) { printf("%cs%ct", c, rev(c)); }
void cp(int c) { printf("%c10%ct", c, rev(c)); }
void cprev(int c) { printf("%c01%ct", c, rev(c)); }
void out(string s) { cout << s; }
void clr(char c) {
  for (int i = (0); i <= (35); ++i) out("l");
  for (int i = (0); i <= (35); ++i) printf("%cr", c);
  putchar(c);
}
int main() {
  for (int i = (0); i <= (35); ++i) out("l");
  for (int i = (0); i <= (40); ++i) {
    ifne('l');
    out("0r");
  }
  for (int i = (0); i <= (40); ++i) ifne('r');
  out("ul");
  for (int i = (0); i <= (35); ++i) out("l");
  for (int i = (0); i <= (40); ++i) {
    ifne('l');
    out("0r");
  }
  for (int i = (0); i <= (40); ++i) ifne('r');
  out("dl");
  for (int _ = (0); _ <= (23); ++_) {
    out("uu");
    clr('e');
    out("u");
    clr('0');
    out("u");
    clr('0');
    out("0dddd");
    for (int i = (0); i <= (36); ++i) {
      if0('u');
      if1('u');
      out("uu1d");
      ifne('d');
      out("dd");
      if1('u');
      if0('u');
      out("uu1d");
      ifne('d');
      out("ddl");
    }
    for (int i = (0); i <= (36); ++i) out("r");
    out("uuu");
    clr('0');
    out("ddd");
    for (int i = (0); i <= (36); ++i) {
      if1('u');
      if1('u');
      ife('u');
      out("1dd");
      ife('u');
      ife('u');
      for (int j = (0); j <= (3); ++j) {
        out("d");
        ife('u');
      }
      out("l");
    }
    for (int i = (0); i <= (36); ++i) out("r");
    out("u");
    clr('e');
    out("u");
    out("u");
    for (int i = (0); i <= (34); ++i) out("l");
    for (int i = (0); i <= (35); ++i) {
      cp('l');
      out("rr");
    }
    out("l0");
  }
  out("u");
  for (int i = (0); i <= (35); ++i) out("l");
  return 0;
}
