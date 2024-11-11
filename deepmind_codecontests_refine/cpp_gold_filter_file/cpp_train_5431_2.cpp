#include <bits/stdc++.h>
#pragma G++ optimize(2)
using namespace std;
inline long long read() {
  char ch = ' ', last;
  long long ans = 0;
  while (ch < '0' || ch > '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + int(ch - '0'), ch = getchar();
  if (last == '-') return -ans;
  return ans;
}
void write(long long x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int n, b[300005], cnt;
double a[300005];
void init() {
  n = read();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0)
      if (int(a[i]) == a[i])
        b[i] = a[i];
      else
        b[i] = a[i] - 1;
    else
      b[i] = a[i];
  }
}
int main() {
  init();
  for (int i = 1; i <= n; i++) cnt += b[i];
  int now = 1;
  while (cnt) {
    if (int(a[now]) != a[now]) b[now]++, cnt++;
    now++;
  }
  for (int i = 1; i <= n; i++) cout << b[i] << endl;
  return 0;
}
