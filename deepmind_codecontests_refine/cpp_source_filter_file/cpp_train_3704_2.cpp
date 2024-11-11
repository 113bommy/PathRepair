#include <bits/stdc++.h>
int main() {
  char c[]{"abcdefghijklmnopqrstuvwxyz"}, d;
  char* p = c;
  std::set<char> e{'a'};
  while (scanf("%c", &d) != EOF) {
    if (d < 'a') break;
    if (!e.count(d)) {
      ++p;
      if (d != *p) {
        printf("NO\n");
        return 0;
      } else
        e.insert(d);
    }
  }
  printf("YES\n");
}
