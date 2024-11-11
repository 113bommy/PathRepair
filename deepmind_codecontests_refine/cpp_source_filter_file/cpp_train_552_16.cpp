#include <bits/stdc++.h>
using namespace std;
int main() {
  int s[100], t[100], n, p, i, j, solv, tim, c;
  scanf("%d%d", &n, &p);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &s[i], &t[i]);
  }
  for (i = 1; i < n; i++)
    for (j = 0; j < n - i; j++)
      if (s[j] < s[j + 1] || (s[j] == s[j + 1] && t[j] > t[j + 1])) {
        swap(s[j], s[j + 1]);
        swap(t[j], t[j + 1]);
      }
  solv = s[p - 1];
  tim = t[p - 1];
  c = 0;
  for (i = p; i >= 0; i--) {
    if (solv == s[i] && t[i] == tim)
      c++;
    else
      break;
  }
  for (i = p + 1; i < n; i++) {
    if (solv == s[i] && t[i] == tim)
      c++;
    else
      break;
  }
  printf("%d", c);
  return 0;
}
