#include <bits/stdc++.h>
using namespace std;
set<pair<string, string> > se;
string hero[10] = {"Anka",   "Chapay", "Cleo",       "Troll",
                   "Dracul", "Snowy",  "Hexadecimal"};
long md, ml;
int na[10], nb[10], nc[10];
long a, b, c;
void dfs(int n1, int n2, int n3, int ind) {
  if (ind == 7) {
    if (n1 == 0 || n2 == 0 || n3 == 0) return;
    long t1 =
        max(max(a / n1, b / n2), c / n3) - min(min(a / n1, b / n2), c / n3);
    if (t1 > md) return;
    int t2 = 0;
    int i, j;
    for (i = 0; i < n1; i++)
      for (j = i + 1; j < n1; j++) {
        if (se.find(make_pair(hero[na[i]], hero[na[j]])) != se.end()) t2++;
        if (se.find(make_pair(hero[na[j]], hero[na[i]])) != se.end()) t2++;
      }
    for (i = 0; i < n2; i++)
      for (j = i + 1; j < n2; j++) {
        if (se.find(make_pair(hero[nb[i]], hero[nb[j]])) != se.end()) t2++;
        if (se.find(make_pair(hero[nb[j]], hero[nb[i]])) != se.end()) t2++;
      }
    for (i = 0; i < n3; i++)
      for (j = i + 1; j < n3; j++) {
        if (se.find(make_pair(hero[nc[i]], hero[nc[j]])) != se.end()) t2++;
        if (se.find(make_pair(hero[nc[j]], hero[nc[i]])) != se.end()) t2++;
      }
    if (t1 < md || ml < t2) {
      md = t1;
      ml = t2;
    }
    return;
  }
  na[n1] = ind;
  dfs(n1 + 1, n2, n3, ind + 1);
  nb[n2] = ind;
  dfs(n1, n2 + 1, n3, ind + 1);
  nc[n3] = ind;
  dfs(n1, n2, n3 + 1, ind + 1);
}
int main() {
  int i, n;
  string p, o, q;
  while (scanf("%d", &n) != EOF) {
    se.clear();
    for (i = 0; i < n; i++) {
      cin >> p >> o >> q;
      se.insert(make_pair(p, q));
    }
    scanf("%ld%ld%ld", &a, &b, &c);
    md = 200000000;
    ml = 0;
    dfs(0, 0, 0, 0);
    printf("%ld %ld\n", md, ml);
  }
  return 0;
}
