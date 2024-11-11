#include <bits/stdc++.h>
using namespace std;
map<string, int> p;
int main() {
  int num, i, j, k;
  string op, a, b;
  scanf("%d", &num);
  p["void"] = 0;
  while (num--) {
    cin >> op >> a;
    if (op == "typedef") {
      cin >> b;
      for (i = 0; a[i] == '&'; ++i)
        ;
      for (j = a.length() - 1, k = 0; a[j] == '*'; --j, ++k)
        ;
      map<string, int>::iterator it = p.find(a.substr(i, j - i + 1));
      if (it == p.end()) {
        p[b] = -1;
        continue;
      } else if (it->second < 0 || it->second + k < 0) {
        p[b] = -1;
        continue;
      }
      p[b] = it->second + k - i;
    } else {
      for (i = 0; a[i] == '&'; ++i)
        ;
      for (j = a.length() - 1, k = 0; a[j] == '*'; --j, ++k)
        ;
      a = a.substr(i, j - i + 1);
      map<string, int>::iterator it = p.find(a);
      if (it == p.end()) {
        puts("errtype");
        continue;
      } else if (it->second < 0 || it->second + k - i < 0) {
        puts("errtype");
        continue;
      }
      printf("void");
      k += p[a] - i;
      for (i = 0; i < k; ++i) putchar('*');
      puts("");
    }
  }
  return 0;
}
