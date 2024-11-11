#include <bits/stdc++.h>
using namespace std;
int L, m;
char a[1000];
int pan() {
  int j, i;
  set<char> s;
  for (i = 0; i < L; i++) {
    s.insert(a[i]);
  }
  if (s.size() > m)
    return 1;
  else
    return 0;
}
int main() {
  int j, i, w;
  scanf("%d", &w);
  while (w--) {
    scanf("%s %d", a, &m);
    L = strlen(a);
    i = 0;
    while (pan()) {
      set<char> s;
      for (i = 0; i < L; i++) {
        s.insert(a[i]);
        if (s.size() > m) {
          while (a[i] == '9') i--;
          a[i]++;
          for (j = i + 1; j < L; j++) a[j] = '0';
          break;
        }
      }
    }
    printf("%s\n", a);
  }
  return 0;
}
