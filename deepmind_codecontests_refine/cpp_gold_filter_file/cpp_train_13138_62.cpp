#include <bits/stdc++.h>
using namespace std;
char s[1000009];
int p[1000009];
int n;
void compute_prefix_function() {
  char _s[1000009];
  for (int i = 1; i <= n; i++) _s[i] = s[i - 1];
  int q = 0;
  p[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (q && _s[q + 1] != _s[i]) q = p[q];
    if (_s[q + 1] == _s[i]) q++;
    p[i] = q;
  }
  for (int i = 0; i < n; i++) p[i] = p[i + 1];
  p[n] = 0;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  compute_prefix_function();
  if (n < 3) {
    printf("Just a legend");
    return 0;
  }
  int mx = *max_element(p + 1, p + n - 1);
  int q = p[n - 1];
  while (mx < q && q) {
    q = p[q - 1];
  }
  if (min(q, mx) == 0)
    printf("Just a legend");
  else {
    for (int i = 0; i < min(q, mx); i++) printf("%c", s[i]);
  }
}
