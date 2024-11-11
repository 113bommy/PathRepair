#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, d, f[100] = {0};
  float k;
  char c, cc[1000];
  map<string, float> a;
  map<string, float>::iterator it;
  string s;
  scanf("%i %i %f\n", &n, &m, &k);
  for (i = 0; i < n; i++) {
    c = 'q';
    s.clear();
    while (c != ' ') {
      scanf("%c", &c);
      if (c != ' ') s = s + c;
    }
    scanf("%i\n", &d);
    a[s] = d * k;
  }
  i = 0;
  for (it = a.begin(); it != a.end(); it++) {
    i++;
    if (it->second < 100) {
      it->second = -10;
    }
  }
  for (i = 0; i < m; i++) {
    s.clear();
    gets(cc);
    cc[strlen(cc)] = '\0';
    s = s + cc;
    it = a.find(s);
    if (it == a.end())
      a[s] = -1;
    else if (it->second == -10)
      it->second = 0;
  }
  i = 0;
  int p = 0;
  for (it = a.begin(); it != a.end(); it++) {
    i++;
    if (it->second != -10) p++;
  }
  printf("%i\n", p);
  for (it = a.begin(); it != a.end(); it++) {
    i++;
    if (it->second != -10) {
      for (i = 0; i < it->first.length(); i++) cc[i] = it->first[i];
      cc[i] = '\0';
      for (i = 0; i < strlen(cc); i++) printf("%c", cc[i]);
      if (it->second == -1) it->second = 0;
      printf(" %i\n", int(it->second));
    }
  }
  getchar();
  getchar();
  return (0);
}
