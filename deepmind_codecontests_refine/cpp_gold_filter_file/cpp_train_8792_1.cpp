#include <bits/stdc++.h>
using namespace std;
struct Node {
  int c, d;
};
const int SIZE = 1e5 + 5;
int res[SIZE];
Node parts[SIZE];
Node actor[SIZE];
int cnt[SIZE];
int ipart[SIZE];
int iact[SIZE];
struct cmp {
  int operator()(int a, int b) { return actor[a].d < actor[b].d; }
};
multiset<int, cmp> myset;
int cmpp(int a, int b) { return parts[a].c < parts[b].c; }
int cmpa(int a, int b) { return actor[a].c < actor[b].c; }
int main() {
  int i, j;
  int n, m;
  cin >> n;
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &parts[i].c, &parts[i].d);
    ipart[i] = i;
  }
  cin >> m;
  for (i = 0; i < m; ++i) {
    scanf("%d%d%d", &actor[i].c, &actor[i].d, cnt + i);
    iact[i] = i;
  }
  sort(ipart, ipart + n, cmpp);
  sort(iact, iact + m, cmpa);
  j = 0;
  multiset<int, cmp>::iterator it;
  for (i = 0; i < n; ++i) {
    while (j < m && actor[iact[j]].c <= parts[ipart[i]].c)
      myset.insert(iact[j++]);
    actor[m].d = parts[ipart[i]].d;
    it = myset.lower_bound(m);
    if (it != myset.end()) {
      res[ipart[i]] = *it;
      --cnt[*it];
      if (cnt[*it] == 0) myset.erase(it);
    } else
      break;
  }
  if (i == n) {
    cout << "YES\n";
    for (i = 0; i < n; ++i) {
      if (i) putchar(' ');
      printf("%d", res[i] + 1);
    }
    cout << endl;
  } else
    cout << "NO\n";
  return 0;
}
