#include <bits/stdc++.h>
using namespace std;
int n;
char s[2011], t[2011], buf[2011];
int cx[256];
bool ok = true;
void op(int i) {
  for (register int j = i; j < n; ++j) buf[j] = t[j];
  int c = n - i;
  for (register int j = n - 1; j >= c; --j) t[j] = t[j - c];
  for (register int j = 0; j < c; ++j) t[c - j - 1] = buf[i + j];
}
vector<int> answ;
void use(int i, int d) {
  for (register int j = d; j < n; ++j) {
    if (t[j] == s[i]) {
      answ.push_back(n - j), op(j);
      if (d + n - j != n) answ.push_back(n - d + j), op(d + n - j);
      answ.push_back(d + 1), op(n - d - 1);
      return;
    }
  }
}
void cont(int d) {
  answ.push_back(n - d), op(d);
  answ.push_back(d), op(n - d);
}
int main(void) {
  scanf("%d", &n);
  scanf("%s", t);
  scanf("%s", s);
  for (register int i = 0; i < n; ++i) ++cx[s[i]];
  for (register int i = 0; i < n; ++i) --cx[t[i]];
  for (register int i = 0; i < 256; ++i) ok &= cx[i] >= 0;
  if (ok) {
    int i = n >> 1, d = 0;
    use(i, d++);
    int l = i - 1, r = i + 1;
    bool isR = false;
    while (l >= 0 || r < n) {
      if (isR) {
        if (r < n)
          use(r, d++), ++r;
        else
          cont(d);
      } else {
        if (l >= 0)
          use(l, d++), --l;
        else
          cont(d);
      }
      isR ^= true;
    }
    if (isR) answ.push_back(n), op(n);
    printf("%d\n", answ.size());
    for (int x : answ) printf("%d ", x);
    putc('\n', stdout);
  } else
    puts("-1");
  return 0;
}
