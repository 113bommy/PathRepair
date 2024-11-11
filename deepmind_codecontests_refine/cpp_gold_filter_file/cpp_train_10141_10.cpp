#include <bits/stdc++.h>
using namespace std;
char s[1000002];
int N;
int main() {
  int ret = 0, c = 0, ind;
  scanf("%s", s);
  N = strlen(s);
  ind = N - 1;
  if (N <= 3) return printf("1\n"), 0;
  while (ind >= 0 && s[ind] != s[(ind + 1) % N]) {
    c++;
    ind--;
  }
  int i = 0;
  for (; i <= ind && s[i] != s[(i + 1) % N]; i++) c++;
  if (c >= 3) ret += (c - 1 + (i > ind)) / 2;
  c = 0;
  for (; i <= ind; i++) {
    if (s[i] != s[(i + 1) % N])
      c++;
    else {
      if (c >= 3) ret += (c - 1) / 2;
      c = 0;
    }
  }
  char last = s[N - 1];
  int cnt = 0;
  ind = N - 1;
  while (ind >= 0 && s[ind] == s[N - 1]) {
    cnt++;
    ind--;
  }
  ind++;
  s[ind] = '#';
  for (int i = 0; i <= ind; i++) {
    if (s[i] != last) {
      if (cnt > 1) ret++;
      cnt = 0;
    }
    cnt++;
    last = s[i];
  }
  printf("%d\n", ret);
}
