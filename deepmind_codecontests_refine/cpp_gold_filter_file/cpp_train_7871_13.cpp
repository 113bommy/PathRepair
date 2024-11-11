#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch = getchar();
  x = 0;
  int e = 1;
  for (; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') e = -1, ch = getchar();
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - 48, ch = getchar())
    ;
  x *= e;
}
inline void read(long long &x) {
  char ch = getchar();
  x = 0;
  int e = 1;
  for (; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') e = -1, ch = getchar();
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - 48, ch = getchar())
    ;
  x *= e;
}
inline void write(int data) {
  if (data < 0) data = -data, putchar('-');
  if (data > 9) write(data / 10);
  putchar(data % 10 + 48);
}
inline void write(long long data) {
  if (data < 0) data = -data, putchar('-');
  if (data > 9) write(data / 10);
  putchar(data % 10 + 48);
}
int a0[10], a1[10];
int n;
int opera(int x, char ch, int y) {
  if (ch == '|') return x | y;
  if (ch == '&') return x & y;
  if (ch == '^') return x ^ y;
}
int main() {
  read(n);
  for (int i = 0; i <= 9; ++i) a0[i] = 0, a1[i] = 1;
  char ch;
  int val;
  for (int i = 1; i <= n; ++i) {
    ch = getchar(), read(val);
    for (int j = 0; j <= 9; ++j) {
      int Val = ((1 << j) & val) > 0;
      a0[j] = opera(a0[j], ch, Val), a1[j] = opera(a1[j], ch, Val);
    }
  }
  int valor = 0, valand = (1 << 10) - 1, valxor = 0;
  for (int i = 0; i <= 9; ++i) {
    int Val = 1 << i;
    if (a1[i] == 1 && a0[i] == 1) valor |= Val;
    if (a1[i] == 0 && a0[i] == 0) valand ^= Val;
    if (a1[i] == 0 && a0[i] == 1) valxor |= Val;
  }
  puts("3");
  cout << "| " << valor << endl;
  cout << "& " << valand << endl;
  cout << "^ " << valxor << endl;
}
