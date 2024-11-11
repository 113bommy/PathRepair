#include <bits/stdc++.h>
using namespace std;
char *FS, *FT, BB[1 << 15];
long long read() {
  long long x = 1, i = 0;
  char ch;
  ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
            ? EOF
            : *FS++);
  while (!isdigit(ch)) {
    if (ch == EOF) {
      exit(0);
    }
    if (ch == '-') x = -1;
    ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
              ? EOF
              : *FS++);
  }
  while (isdigit(ch)) {
    i = i * 10 + ch - '0';
    ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
              ? EOF
              : *FS++);
  }
  return x * i;
}
long long get(char *S) {
  char ch;
  long long l = 0;
  ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
            ? EOF
            : *FS++);
  while (!isalnum(ch)) {
    if (ch == EOF) {
      exit(0);
    }
    ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
              ? EOF
              : *FS++);
  }
  while (isalnum(ch)) {
    S[l++] = ch;
    ch = (FS == FT && (FT = (FS = BB) + fread(BB, 1, 1 << 15, stdin), FS == FT)
              ? EOF
              : *FS++);
  }
  return l;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int check(int x) {}
long long v[100005];
int main() {
  long long n = read();
  for (long long i = 1; i <= 2 * n; ++i) v[i] = read();
  sort(v + 1, v + 1 + 2 * n);
  long long ans = (v[2 * n] - v[n + 1]) * (v[n] - v[1]);
  for (long long i = 2; i <= n; ++i)
    ans = min(ans, (v[i + n - 1] - v[i]) * (v[2 * n] - v[1]));
  write(ans);
  return 0;
}
