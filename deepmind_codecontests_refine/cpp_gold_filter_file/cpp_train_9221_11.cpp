#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  x = 0;
  long long f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  x *= f;
  return;
}
long long fs(long long x) { return x < 0 ? -x : x; }
void print(long long x) {
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  print(x / 10);
  putchar(x % 10 + '0');
  return;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = fs(x);
  }
  print(x);
  return;
}
long long mint(long long x, long long y) { return x < y ? x : y; }
long long maxt(long long x, long long y) { return x > y ? x : y; }
queue<long long> q;
long long n, k, a[2005], cnt[2005];
int main() {
  read(n), read(k);
  for (int i = 1; i <= k; i++) {
    long long p;
    read(p);
    p = p - n + 1000;
    ++cnt[p];
  }
  for (int i = 0 - n + 1000; i <= 1000 - n + 1000; i++) {
    a[i] = 0x3f3f3f3f3f3f3f;
    if (cnt[i]) a[i] = 1, q.push(i);
  }
  while (!q.empty()) {
    long long p = q.front();
    q.pop();
    for (int i = 0; i <= 1000; i++)
      if (a[i - n + 1000] == 1) {
        long long rt = p + i - n;
        if (a[rt] != 0x3f3f3f3f3f3f3f) continue;
        a[rt] = a[p] + 1;
        q.push(rt);
      }
  }
  if (a[1000] == 0x3f3f3f3f3f3f3f)
    puts("-1");
  else
    printf("%lld", a[1000]);
}
