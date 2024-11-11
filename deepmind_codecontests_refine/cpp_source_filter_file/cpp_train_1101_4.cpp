#include <bits/stdc++.h>
std::set<int> a;
std::map<long long, int> b;
bool isPermited(int val) { return a.find(val) == a.end(); }
int main(void) {
  int b1, q, l, m;
  scanf("%d%d%d%d", &b1, &q, &l, &m);
  for (int i = 0; i < m; i++) {
    int val;
    scanf("%d", &val);
    a.insert(val);
  }
  int countOnce = 0;
  int countInfinite = 0;
  long long bi = b1;
  while (abs(bi) <= l && b[bi] < 2) {
    b[bi]++;
    if (isPermited(bi)) {
      if (b[bi] == 1)
        countOnce++;
      else
        countInfinite++;
    }
    bi *= q;
  }
  if (countInfinite > 0)
    printf("inf\n");
  else
    printf("%d\n", countOnce);
  return 0;
}
