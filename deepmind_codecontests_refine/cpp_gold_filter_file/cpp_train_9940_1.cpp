#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
set<int> H, V;
set<int>::iterator i, j;
int Hn[MAXN], Vn[MAXN];
void cut(set<int> &s, int *N, int v) {
  s.insert(v);
  i = j = s.find(v);
  i--;
  j++;
  N[*j - *i]--;
  N[*j - v]++;
  N[v - *i]++;
}
int main() {
  int w, h, n;
  scanf("%d%d%d", &w, &h, &n);
  H.insert(0);
  V.insert(0);
  H.insert(h);
  V.insert(w);
  Hn[h] = 1;
  Vn[w] = 1;
  char ch;
  int p;
  while (n--) {
    scanf(" %c%d", &ch, &p);
    ch == 'H' ? cut(H, Hn, p) : cut(V, Vn, p);
    while (!Hn[h]) h--;
    while (!Vn[w]) w--;
    printf("%I64d\n", 1LL * h * w);
  }
  return 0;
}
