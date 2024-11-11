#include <bits/stdc++.h>
using namespace std;
char str[200006];
bool eq_pos(int z, int o, int q) {
  int n = z + o + q;
  int h = n / 2;
  if (n % 2) {
    if (z <= h && o <= (h + 1)) return true;
  } else {
    if (z <= h && o <= h) return true;
  }
  return false;
}
void upd(char ch, set<int> &S) {
  if (ch == '0')
    S.insert(2);
  else
    S.insert(1);
}
void burn(set<int> &S) {
  int n, i, z, o, q;
  z = o = q = 0;
  for (i = 0; str[i]; ++i) {
    if (str[i] == '0')
      ++z;
    else if (str[i] == '1')
      ++o;
    else
      ++q;
  }
  n = z + o + q;
  if (o + q - 2 >= z) S.insert(3);
  if (z + q - 1 - (n % 2 == 0) >= o) S.insert(0);
  if (eq_pos(z, o, q)) upd(str[n - 1], S);
}
int main() {
  int n, i, j, x;
  bool f;
  set<int> S;
  set<int>::iterator is;
  while (scanf("%s", str) != EOF) {
    S.clear();
    n = strlen(str);
    f = str[n - 2] == '?';
    if (f) {
      for (j = 0; j < 2; ++j) {
        str[n - 1] = j + '0';
        burn(S);
      }
    } else
      burn(S);
    for (is = S.begin(); is != S.end(); ++is) {
      x = *is;
      printf("%d%d\n", (x & 2) > 0, (x & 1) > 0);
    }
  }
  return 0;
}
