#include <bits/stdc++.h>
using namespace std;
struct aa {
  int a[4];
} Ans[1010];
int ans, n, i, j, num, a[110];
long long T;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void work(int x) {
  if (x == 0) {
    ans++;
    Ans[ans] = (aa){n + 1, n - 1, n + 1, n};
    ans++;
    Ans[ans] = (aa){n + 2, n - 1, n + 2, n};
    ans++;
    Ans[ans] = (aa){n - 1, n + 1, n, n + 1};
    ans++;
    Ans[ans] = (aa){n - 1, n + 2, n, n + 2};
    return;
  }
  if (x == 1) {
    ans++;
    Ans[ans] = (aa){n + 1, n - 1, n + 1, n};
    ans++;
    Ans[ans] = (aa){n - 1, n + 1, n, n + 1};
    ans++;
    Ans[ans] = (aa){n - 1, n + 2, n, n + 2};
    return;
  }
  if (x == 2) {
    ans++;
    Ans[ans] = (aa){n + 1, n - 1, n + 1, n};
    ans++;
    Ans[ans] = (aa){n - 1, n + 1, n, n + 1};
    return;
  }
  if (x == 3) {
    ans++;
    Ans[ans] = (aa){n + 2, n - 1, n + 2, n};
    ans++;
    Ans[ans] = (aa){n - 1, n + 1, n, n + 1};
    ans++;
    Ans[ans] = (aa){n - 1, n + 2, n, n + 2};
    return;
  }
  if (x == 4) {
    ans++;
    Ans[ans] = (aa){n + 1, n - 1, n + 1, n};
    ans++;
    Ans[ans] = (aa){n + 2, n - 1, n + 2, n};
    return;
  }
  ans++;
  Ans[ans] = (aa){n + 1, n - 1, n + 1, n};
}
int main() {
  T = read();
  while (T) {
    num++;
    a[num] = T % 6;
    T /= 6;
  }
  for (i = 1; i <= num / 2; i++) swap(a[i], a[num - i + 1]);
  n = 2;
  ans = 2;
  Ans[1] = (aa){1, 2, 2, 2};
  Ans[2] = (aa){2, 1, 2, 2};
  for (i = 1; i <= num; i++) {
    work(a[i]);
    n += 2;
    if (i == num) break;
    ans++;
    Ans[ans] = (aa){n, n - 1, n + 1, n - 1};
    ans++;
    Ans[ans] = (aa){n, n - 2, n + 1, n - 2};
    ans++;
    Ans[ans] = (aa){n + 1, n - 3, n + 2, n - 3};
    ans++;
    Ans[ans] = (aa){n + 1, n - 2, n + 2, n - 2};
    ans++;
    Ans[ans] = (aa){n - 1, n, n - 1, n + 1};
    ans++;
    Ans[ans] = (aa){n - 2, n, n - 2, n + 1};
    ans++;
    Ans[ans] = (aa){n - 2, n + 1, n - 2, n + 2};
    ans++;
    Ans[ans] = (aa){n - 3, n + 1, n - 3, n + 2};
  }
  write(n);
  putchar(' ');
  write(n);
  puts("");
  write(ans);
  puts("");
  for (i = 1; i <= ans; i++) {
    for (j = 0; j <= 3; j++) write(Ans[i].a[j]), putchar(' ');
    puts("");
  }
}
