#include <bits/stdc++.h>
const int maxn = 1058576;
using namespace std;
char second[maxn];
int main() {
  int line = 1;
  bool r = 1;
  while (gets(second)) {
    int n = strlen(second);
    int i;
    for (i = 0; second[i] == ' ' && i < n; ++i)
      ;
    if (second[i] == '#') {
      if (line != 1) printf("\n");
      printf("%s", second);
      r = 1;
    } else {
      if (r) printf("\n");
      for (int k = 0; k < n; ++k)
        if (second[k] != ' ') cout << second[k];
      r = 0;
    }
    line += 1;
  }
  cout << "\n";
  return 0;
}
