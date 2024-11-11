#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long readll() {
  long long x = 0;
  bool ok = 0;
  char c = getchar();
  while (c < 48 or c > 57) ok |= (c == '-'), c = getchar();
  while (c > 47 and c < 58) x = (x << 3) + (x << 1) + c - 48, c = getchar();
  if (ok) x = -x;
  return x;
}
int read() {
  int x = 0;
  bool ok = 0;
  char c = getchar();
  while (c < 48 or c > 57) ok |= (c == '-'), c = getchar();
  while (c > 47 and c < 58) x = (x << 3) + (x << 1) + c - 48, c = getchar();
  if (ok) x = -x;
  return x;
}
void print(long long x, bool y = 0) {
  if (x < 0) putchar('-'), x = -x;
  char s[20];
  int p = 0;
  if (x == 0) s[p++] = 48;
  while (x > 0) s[p++] = x % 10 + 48, x /= 10;
  while (p--) putchar(s[p]);
  if (y == 0)
    puts("");
  else
    putchar(' ');
}
string read_s() {
  string s = "";
  char c = getchar();
  while (c == '\n' || c == '\t' || c == ' ') c = getchar();
  while (c != '\n' && c != '\t' && c != ' ') s += c, c = getchar();
  return s;
}
char read_c() {
  char c = getchar();
  while (c != '\n' && c != '\t' && c != ' ') c = getchar();
  return c;
}
void prints(string x) {
  char *s = new char(x.size() + 1);
  for (int i = 0; i < x.size(); i++) s[i] = x[i];
  s[x.size()] = '\0';
  puts(s);
}
int main() {
  long long n = read(), k = read();
  if (k == 1) {
    print(n);
    return 0;
  }
  long long j = 0;
  for (int i = 59; i >= 0; i--) {
    if ((n >> i) & 1) {
      j = i;
      break;
    }
  }
  print((1LL << (j + 1)) - 1);
  return 0;
}
