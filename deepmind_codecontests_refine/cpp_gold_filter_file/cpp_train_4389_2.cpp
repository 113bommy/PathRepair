#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N], t[N];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = n; i >= 1; --i) {
    s[i] -= 'a';
    t[i] -= 'a';
    s[i] += t[i];
    s[i - 1] += s[i] / 26;
    s[i] %= 26;
  }
  int ptr = 1;
  int first = 1;
  if (s[0]) --ptr;
  for (int i = ptr; i <= n; ++i) {
    if (s[i] & 1) {
      s[i + 1] += 26;
    }
    s[i] >>= 1;
  }
  for (int i = 1; i <= n; ++i) {
    putchar(s[i] + 'a');
  }
  return 0;
}
