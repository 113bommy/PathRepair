#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, i, j, a[1000005], b[1000005], _ = 0x1bbbbbbbbbbbbbbbll, sum;
void solve(long long x) {
  long long ans = 0, mid, tmp, i;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    b[i] = a[i] % x;
  }
  tmp = 0;
  mid = -1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    if (mid == -1 && tmp + b[i] >= (x + 1) / 2) {
      mid = i;
      ans += tmp * i;
      ans -= (x - tmp) * i;
    }
    long long t = min(b[i], x - tmp);
    tmp += t;
    b[i] -= t;
    if (mid == -1)
      ans -= t * i;
    else
      ans += t * i;
    if (tmp == x) {
      tmp = 0;
      mid = -1;
      i--;
    }
  }
  _ = min(ans, _);
}
int main() {
  read(n);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    read(a[i]);
    sum += a[i];
  }
  if (sum == 1) {
    puts("-1");
    return 0;
  }
  long long t = 2;
  while (sum >= t * t) {
    if (sum % t == 0) {
      solve(t);
      while (sum % t == 0) sum /= t;
    }
    t++;
  }
  if (sum) solve(sum);
  cout << _ << endl;
  return 0;
}
