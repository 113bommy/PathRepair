#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
char c[1000010];
int q[1000010];
int bf[1000010];
bool b[1000010];
int l, r;
int main() {
  int i, j, k;
  scanf("%s", c);
  s = c;
  n = s.size();
  for (i = 0; i <= n - 1; i++) {
    q[i] = i + 1;
    bf[i] = i - 1;
  }
  l = r = -1;
  string s1, s2;
  i = 0;
  while (i < n && q[i] < n) {
    if (b[i] == true) {
      i++;
      continue;
    }
    if (s[i] == 'x' && s[q[i]] == 'y') {
      if (bf[i] != -1) {
        q[bf[i]] = q[q[i]];
        bf[q[q[i]]] = bf[i];
        b[i] = true;
        b[q[i]] = true;
        i = bf[i];
      } else {
        bf[q[q[i]]] = -1;
        b[i] = true;
        b[q[i]] = true;
        i = q[q[i]];
      }
    } else
      i = q[i];
  }
  i = 0;
  while (i < n && q[i] < n) {
    if (b[i] == true) {
      i++;
      continue;
    }
    if (s[i] == 'y' && s[q[i]] == 'x') {
      if (bf[i] != -1) {
        q[bf[i]] = q[q[i]];
        bf[q[q[i]]] = bf[i];
        b[i] = true;
        b[q[i]] = true;
        i = bf[i];
      } else {
        bf[q[q[i]]] = -1;
        b[i] = true;
        b[q[i]] = true;
        i = q[q[i]];
      }
    } else
      i = q[i];
  }
  for (i = 0; i <= n - 1; i++) {
    if (b[i] == false) printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
