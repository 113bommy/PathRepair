#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x;
}
bool check(int d, int e, int f) {
  if (e > 12 || f > 31) return 0;
  int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (!(d % 4)) mon[2] = 29;
  if (f > mon[e] || a - d < 18) return 0;
  if (a - d > 18) return 1;
  if (e < b) return 1;
  if (e > b) return 0;
  if (f > c) return 0;
  if (f <= c) return 1;
}
int main() {
  c = read(), b = read(), a = read();
  int d = read(), e = read(), f = read();
  if (check(d, e, f) || check(d, f, e) || check(e, d, f) || check(e, f, d) ||
      check(f, d, e) || check(f, e, d))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
