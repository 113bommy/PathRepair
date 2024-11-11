#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 5;
int n, w[2], dl[2][N];
multiset<int> poz[2], dlu[2];
multiset<int>::iterator it, it2;
void init_set() {
  for (int i = 0; i < 2; i++) {
    poz[i].insert(0);
    dlu[i].insert(w[i]);
    dl[i][0] = w[i];
  }
}
void zapytanie() {
  char ch;
  int kro, a, kto;
  scanf(" %c%d", &ch, &a);
  if (ch == 'V')
    kto = 0;
  else
    kto = 1;
  it = poz[kto].upper_bound(a);
  it--;
  kro = *it;
  poz[kto].insert(a);
  it2 = dlu[kto].find(dl[kto][kro]);
  dlu[kto].erase(it2);
  dl[kto][a] = dl[kto][kro] - (a - kro);
  dl[kto][kro] = a - kro;
  dlu[kto].insert(dl[kto][a]);
  dlu[kto].insert(dl[kto][kro]);
  it = dlu[0].end();
  it--;
  long long wyn = *it;
  it = dlu[1].end();
  it--;
  wyn *= *it;
  printf("%I64d\n", wyn);
}
int main() {
  scanf("%d%d%d", &w[0], &w[1], &n);
  init_set();
  while (n--) zapytanie();
  return 0;
}
