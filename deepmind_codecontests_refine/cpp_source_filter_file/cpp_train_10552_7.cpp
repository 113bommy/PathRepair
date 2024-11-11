#include <bits/stdc++.h>
using namespace std;
bool gprintf(int debug, const char *format, ...) {
  if (0 & debug) {
    va_list listpointer;
    va_start(listpointer, format);
    vfprintf(stderr, format, listpointer);
    va_end(listpointer);
    return true;
  } else
    return false;
}
int main() {
  string s, t;
  int i, j;
  int p, q;
  int longest = 0;
  cin >> s;
  for ((i) = 0; (i) < ((s).size()); (i)++)
    for (j = i; j < (s).size(); j++) {
      t = s.substr(i, j + 1);
      p = s.find(t);
      q = s.rfind(t);
      if (p != q) longest = max(longest, (int)(t).size());
    }
  printf("%d\n", longest);
  return 0;
}
