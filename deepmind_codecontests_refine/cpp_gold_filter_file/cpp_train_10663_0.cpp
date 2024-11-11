#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
  int n, i;
  scanf("%d", &n);
  vector<int> tab(1000000, 0);
  int tmp;
  for (i = 0; i < n; i++) {
    scanf("%d", &tmp);
    tab[tmp - 1]++;
  }
  int cpt = 0;
  vector<int> sol;
  for (i = 0; i < 500000; i++) {
    if (tab[i] == 1 || tab[1000000 - 1 - i] == 1) {
      if (tab[i] == 0)
        sol.push_back(i);
      else if (tab[1000000 - 1 - i] == 0)
        sol.push_back(1000000 - 1 - i);
      else
        cpt++;
    }
  }
  for (i = 0; cpt > 0 && i < 500000; i++) {
    if (tab[i] == 0 && tab[1000000 - 1 - i] == 0) {
      cpt--;
      sol.push_back(i);
      sol.push_back(1000000 - 1 - i);
    }
  }
  assert(cpt == 0);
  printf("%d\n", sol.size());
  for (i = 0; i < sol.size(); i++) {
    printf("%d ", sol[i] + 1);
  }
  return 0;
}
