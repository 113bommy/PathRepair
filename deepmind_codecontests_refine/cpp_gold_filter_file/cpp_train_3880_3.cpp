#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  int x[10] = {}, y[10] = {}, top = -1, t = 0;
  gets(s);
  for (int i = 0; s[i]; i++) {
    x[s[i] - '0']++;
    y[s[i] - '0']++;
  }
  for (int i = 1; i <= 9; i++)
    if (x[i] && y[10 - i]) {
      int sum = 0;
      x[i]--, y[10 - i]--;
      for (int j = 0; j <= 9; j++) sum += min(x[j], y[9 - j]);
      if (sum > top) {
        top = sum;
        t = i;
      }
      x[i]++, y[10 - i]++;
    }
  if (!t) {
    for (int i = 9; ~i; i--)
      while (x[i]--) putchar('0' + i);
    puts("");
    for (int i = 9; ~i; i--)
      while (y[i]--) putchar('0' + i);
    return 0;
  }
  list<int> p, q;
  p.push_front(t);
  q.push_front(10 - t);
  x[t]--, y[10 - t]--;
  for (int i = 0; i <= 9; i++) {
    int c = min(x[i], y[9 - i]);
    for (int j = 0; j < c; j++) {
      p.push_front(i);
      q.push_front(9 - i);
    }
    x[i] -= c, y[9 - i] -= c;
  }
  int c = min(x[0], y[0]);
  for (int j = 0; j < c; j++) {
    p.push_back(0);
    q.push_back(0);
  }
  x[0] -= c, y[0] -= c;
  for (int i = 9; ~i; i--)
    while (x[i]--) p.push_front(i);
  for (int i = 9; ~i; i--)
    while (y[i]--) q.push_front(i);
  for (auto c : p) putchar(c + '0');
  puts("");
  for (auto c : q) putchar(c + '0');
  puts("");
}
