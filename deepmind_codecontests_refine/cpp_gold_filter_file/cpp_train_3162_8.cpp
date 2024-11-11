#include <bits/stdc++.h>
using namespace std;
int tab[101][101];
int n, recnum = 0;
int step(int prew, int last, int &s) {
  if (recnum == n) {
    recnum = 0;
    return 0;
  }
  bool end = true;
  int i;
  for (i = 0; i <= n; i++) {
    if ((tab[last][i]) && (i != prew)) {
      if (tab[last][i] > 0) s += tab[last][i];
      end = false;
      break;
    }
  }
  if (end) return 0;
  recnum++;
  step(last, i, s);
  return 0;
}
int main() {
  int s1 = 0, s2 = 0;
  memset(tab, 0, sizeof(tab));
  scanf("%d", &n);
  int a, b, c;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    tab[a][b] = -1;
    tab[b][a] = c;
  }
  recnum = 1;
  step(a, b, s1);
  recnum = 1;
  s2 += c;
  step(b, a, s2);
  (s1 < s2) ? cout << s1 << endl : cout << s2 << endl;
}
