#include <bits/stdc++.h>
using namespace std;
int n, m, k, d[110];
char s[110];
int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  bool gen = false, cheb = false;
  for (int i = 0; i < (n); i++) {
    int x = -1, y;
    d[i] = -1;
    gets(s);
    bool ok = false;
    for (int j = 0; j < (m); j++)
      if (s[j] != '-') {
        if (x == -1)
          x = j;
        else if (s[x] != s[j])
          d[i] = j - x;
      } else
        ok = true;
    if (d[i] == -1) {
      if (x != -1 || !ok)
        d[i] = 0;
      else {
        if (s[x] == 'G')
          gen = true;
        else
          cheb = true;
      }
    }
  }
  if (gen && cheb) {
    puts("Draw");
    return 0;
  }
  if (gen) {
    puts("First");
    return 0;
  }
  if (cheb) {
    puts("Second");
    return 0;
  }
  bool ok = false;
  for (int i = 0; i < (7); i++) {
    int x = 0;
    for (int j = 0; j < (n); j++) {
      x += d[j] & 1;
      d[j] >>= 1;
    }
    ok |= x % (k + 1);
  }
  puts(ok ? "First" : "Second");
}
