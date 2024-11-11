#include <bits/stdc++.h>
using namespace std;
int n, k;
int abbb[3][1500];
set<pair<int, int> > table;
bool mark[1005][1005];
int main() {
  scanf("%i%i", &n, &k);
  if (2 * k > n - 1) {
    printf("-1\n");
    return 0;
  }
  printf("%i\n", n * k);
  for (int i = 1; i <= n; i++) {
    table.insert(make_pair(i, 0));
  }
  for (int i = 1; i <= n; i++) {
    int abb = 0;
    for (set<pair<int, int> >::iterator it = table.begin(); it != table.end();
         it++) {
      if ((*it).first == i) continue;
      if (mark[(*it).first][i]) continue;
      printf("%i %i\n", i, (*it).first);
      mark[(*it).first][i] = true;
      mark[i][(*it).first] = true;
      abbb[1][abb + 1] = (*it).first;
      abbb[2][abb + 1] = (*it).second + 1;
      abb++;
      if (abb == k) break;
    }
    for (int i = 1; i <= k; i++) {
      table.erase((make_pair(abbb[1][i], abbb[2][i] - 1)));
      if (abbb[2][i] < n - 1 - k) {
        table.insert(make_pair(abbb[1][i], abbb[2][i]));
      }
    }
  }
  return 0;
}
