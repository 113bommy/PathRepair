#include <bits/stdc++.h>
using namespace std;
const int oo = ~0U >> 1;
const double inf = 1e100;
const double eps = 1e-6;
string name = "", in = ".in", out = ".out";
int n, lcm, cnta, cntb, la, lb;
char a[2008], b[2008], ca, cb;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void Work(int limit) {
  int pa = 1, push_back = 1;
  for (int i = 1, tt = limit; i <= tt; ++i) {
    ca = a[pa];
    cb = b[push_back];
    if (ca == 'R') {
      if (cb == 'P') cntb++;
      if (cb == 'S') cnta++;
    }
    if (ca == 'P') {
      if (cb == 'S') cntb++;
      if (cb == 'R') cnta++;
    }
    if (ca == 'S') {
      if (cb == 'R') cntb++;
      if (cb == 'P') cnta++;
    }
    pa = pa % la + 1;
    push_back = push_back % lb + 1;
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  la = strlen(a + 1);
  lb = strlen(b + 1);
  lcm = la * lb / gcd(la, lb);
  Work(min(lcm, n));
  if (lcm <= n) {
    cnta *= n / lcm;
    cntb *= n / lcm;
    Work(n - lcm);
  }
  printf("%d %d\n", cntb, cnta);
  return 0;
}
