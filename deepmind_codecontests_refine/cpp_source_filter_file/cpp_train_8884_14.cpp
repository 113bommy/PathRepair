#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t;
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-')
    __t = -1, a = 0;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a = a * __t;
}
inline int Calc(int a, char op, int b) {
  if (op == '&') return a & b;
  if (op == '|') return a | b;
  return a ^ b;
}
int Next() {
  char c = getchar();
  switch (c) {
    case '0': {
      return 1;
      break;
    }
    case '1': {
      return 4;
      break;
    }
    case '?': {
      return 2;
      break;
    }
  }
  int L, R, ret = 0;
  L = Next();
  c = getchar();
  R = Next();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if ((L & (1 << i)) && (R & (1 << j))) ret |= 1 << Calc(i, c, j);
  getchar();
  return ret;
}
int main() {
  scanf("%d\n", &n);
  if (Next() & 2)
    printf("YES");
  else
    printf("NO");
}
