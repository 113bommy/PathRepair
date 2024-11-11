#include <bits/stdc++.h>
using namespace std;
string s;
int a[10], b[10];
deque<int> q, d;
int main() {
  cin >> s;
  for (int i = 0; s[i]; i++) a[s[i] - '0']++;
  memcpy(b, a, sizeof(a));
  int z = -1, mark;
  for (int i = 1; i <= 5; i++)
    if (a[i] && b[10 - i]) {
      a[i]--;
      b[10 - i]--;
      int t = 0;
      for (int i = 1; i < 9; i++) t += min(a[i], b[9 - i]);
      if (t > z) {
        z = t;
        mark = i;
      }
      a[i]++;
      b[10 - i]++;
    }
  if (z == -1) {
    for (int i = 9; i >= 0; i--)
      while (a[i]--) printf("%d", i);
    puts("");
    for (int i = 9; i >= 0; i--)
      while (b[i]--) printf("%d", i);
    puts("");
  } else {
    q.push_front(mark);
    d.push_front(10 - mark);
    a[mark]--;
    b[10 - mark]--;
    for (int i = 0; i < 10; i++) {
      int t = min(a[i], b[9 - i]);
      a[i] -= t;
      b[9 - i] -= t;
      while (t--) {
        q.push_front(i);
        d.push_front(9 - i);
      }
    }
    int j = 0;
    for (int i = 0; i <= 9; i++)
      if (a[i] >= 0) {
        while (a[i]--) {
          while (b[j] == 0 && j < 10) j++;
          b[j]--;
          if (!i && !j) {
            q.push_back(i);
            d.push_back(j);
          } else {
            q.push_front(i);
            d.push_front(j);
          }
        }
      }
    int tmp = a[0];
    while (!q.empty()) printf("%d", q.front()), q.pop_front();
    puts("");
    while (!d.empty()) printf("%d", d.front()), d.pop_front();
    puts("");
  }
  return 0;
}
