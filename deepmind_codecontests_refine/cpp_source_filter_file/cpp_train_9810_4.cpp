#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &cn) {
  char c;
  int sig = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') sig = -1;
  cn = c - 48;
  while (isdigit(c = getchar())) cn = cn * 10 + c - 48;
  cn *= sig;
}
template <typename T>
void Write(T cn) {
  if (cn < 0) {
    putchar('-');
    cn = 0 - cn;
  }
  int wei = 0;
  T cm = 0;
  int cx = cn % 10;
  cn /= 10;
  while (cn) cm = cm * 10 + cn % 10, cn /= 10, wei++;
  while (wei--) putchar(cm % 10 + 48), cm /= 10;
  putchar(cx + 48);
}
int n, t;
char c[10000 + 1];
char ans[10000 + 1];
int ansz;
char d[10000 + 1];
int dlen;
void getit(char c[], int &clen) {
  while (!isalpha(c[1] = getchar()))
    ;
  clen = 1;
  while (isalpha(c[++clen] = getchar()))
    ;
  clen--;
}
void zuo() {
  Read(n);
  getit(c, n);
  ansz = 1;
  for (int i = 1; i <= n; i++) ans[i] = c[i];
  for (int i = 2; i <= n; i++) {
    dlen = 0;
    for (int j = i; j <= n; j++) d[++dlen] = c[j];
    if ((n - i) & 1)
      for (int j = 1; j <= i - 1; j++) d[++dlen] = c[j];
    else
      for (int j = i - 1; j >= 1; j--) d[++dlen] = c[j];
    int lin = -1;
    for (int j = 1; j <= n; j++)
      if (d[j] != c[j]) {
        lin = d[j] < ans[j];
        break;
      }
    if (lin == 1) {
      ansz = i;
      for (int j = 1; j <= n; j++) ans[j] = d[j];
    }
  }
  for (int i = 1; i <= n; i++) putchar(ans[i]);
  puts("");
  Write(ansz);
  puts("");
}
int main() {
  Read(t);
  while (t--) zuo();
  return 0;
}
