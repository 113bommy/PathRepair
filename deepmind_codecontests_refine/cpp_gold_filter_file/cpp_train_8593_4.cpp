#include <bits/stdc++.h>
using namespace std;
const long nmax = 1e5 + 3;
struct node {
  long ok, t[2];
};
node ds[10 * nmax];
long n, cnt = 1;
string s;
void trans() {
  long i;
  s.erase(0, 2);
  for (i = 0; i < n; i++)
    if ((int(s[i]) - int('0')) % 2 == 0)
      s[i] = '0';
    else
      s[i] = '1';
  for (i = 0; i <= 17 - n; i++) s = '0' + s;
}
void update(long h) {
  long v = 1, j;
  for (long i = 17; i >= 0; i--) {
    j = (s[i] != '0');
    if (ds[v].t[j] == 0) ds[v].t[j] = ++cnt;
    v = ds[v].t[j];
  }
  ds[v].ok += h;
}
void solve_1() {
  trans();
  update(1);
}
void solve_2() {
  trans();
  update(-1);
}
long get() {
  long v = 1, j;
  for (long i = 17; i >= 0; i--) {
    j = (s[i] != '0');
    v = ds[v].t[j];
  }
  return (ds[v].ok);
}
void solve_3() {
  trans();
  printf("%ld\n", get());
}
int main() {
  long t;
  scanf("%ld\n", &t);
  while (t > 0) {
    getline(cin, s);
    n = s.length() - 2;
    if (s[0] == '+')
      solve_1();
    else if (s[0] == '-')
      solve_2();
    else
      solve_3();
    t--;
  }
}
