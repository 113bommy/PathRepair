#include <bits/stdc++.h>
using namespace std;
int n, cur, h, val, maxim;
char buf[2000];
int main() {
  scanf("%d\n", &n);
  gets(buf);
  for (int i = n; i < 2 * n; ++i) buf[i] = buf[n - i];
  for (int i = 0; i < n; ++i)
    if (buf[i] == 'H') h++;
  for (int i = 0; i < h; ++i)
    if (buf[i] == 'H') val++;
  maxim = val;
  for (int i = h; i < 2 * n; ++i) {
    if (buf[i] == 'H') val++;
    if (buf[i - h] == 'H') val--;
    maxim = ((maxim < val) ? (val) : (maxim));
  }
  cout << (h - maxim);
  return 0;
}
