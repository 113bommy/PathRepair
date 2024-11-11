#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T modul(T x) {
  return ((x < 0) ? -x : x);
}
template <class T>
inline T minim(T x, T y) {
  return ((x < y) ? x : y);
}
template <class T>
inline T maxim(T x, T y) {
  return ((x > y) ? x : y);
}
bool er = false;
int a, b;
char c[1000];
long long nr;
int rez[1000];
char rez1[1000];
inline void citire() {
  scanf("%d ", &a);
  fgets(c, 1000, stdin);
  int i = 0;
  for (; c[i] == ' '; ++i)
    ;
  if (c[i] == 'R')
    er = true;
  else
    sscanf(c + i, "%d", &b);
  fgets(c, 1000, stdin);
}
inline void to10() {
  int i = 0;
  for (; ('0' <= c[i] && c[i] <= '9') || ('A' <= c[i] && c[i] <= 'Z'); ++i)
    ;
  --i;
  long long a1 = 1;
  long long cat;
  for (; i >= 0; --i) {
    if ('0' <= c[i] && c[i] <= '9')
      cat = c[i] - '0';
    else if ('A' <= c[i] && c[i] <= 'Z')
      cat = 10 + c[i] - 'A';
    else
      cat = 10 + c[i] - 'a';
    nr += a1 * cat;
    a1 *= (long long)a;
  }
}
inline void scrie(int x) {
  if (x < 10)
    printf("%d", x);
  else {
    char aux = 'A' + (x - 10);
    printf("%c", aux);
  }
}
inline void from10() {
  if (nr == 0) {
    printf("0");
    return;
  }
  rez[0] = 0;
  long long b1 = (long long)b;
  while (nr > 0) {
    rez[++rez[0]] = nr % b1;
    nr /= b1;
  }
  for (int i = rez[0]; i > 0; --i) scrie(rez[i]);
}
inline void from10R() {
  int n = 0;
  while (nr >= 1000) {
    nr -= 1000;
    rez1[++n] = 'M';
  }
  if (nr >= 900) {
    nr -= 900;
    rez1[++n] = 'C';
    rez1[++n] = 'M';
  }
  if (nr >= 500) {
    nr -= 500;
    rez1[++n] = 'D';
  }
  if (nr >= 400) {
    nr -= 400;
    rez1[++n] = 'C';
    rez1[++n] = 'D';
  }
  while (nr >= 100) {
    nr -= 100;
    rez1[++n] = 'C';
  }
  if (nr >= 90) {
    nr -= 90;
    rez1[++n] = 'X';
    rez1[++n] = 'C';
  }
  if (nr >= 50) {
    nr -= 50;
    rez1[++n] = 'L';
  }
  if (nr >= 40) {
    nr -= 40;
    rez1[++n] = 'X';
    rez1[++n] = 'L';
  }
  while (nr >= 10) {
    nr -= 10;
    rez1[++n] = 'X';
  }
  if (nr >= 9) {
    nr -= 9;
    rez1[++n] = 'I';
    rez1[++n] = 'X';
  }
  if (nr >= 5) {
    nr -= 5;
    rez1[++n] = 'V';
  }
  if (nr >= 4) {
    nr -= 4;
    rez1[++n] = 'I';
    rez1[++n] = 'V';
  }
  while (nr >= 1) {
    nr -= 1;
    rez1[++n] = 'I';
  }
  rez1[n + 1] = '\0';
  fputs(rez1 + 1, stdout);
}
int main() {
  citire();
  to10();
  if (er == false)
    from10();
  else
    from10R();
  printf("\n");
  return 0;
}
