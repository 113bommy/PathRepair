#include <bits/stdc++.h>
using namespace std;
vector<int> poz[200010];
set<int> m;
set<int>::iterator it;
int v1[200010], v[200010], sol[200010], first[200010], last[200010],
    aib[200010], n;
void update(int poz) {
  for (int i = poz; i <= n; i += i & (-i)) aib[i]++;
}
int query(int poz) {
  int s = 0;
  for (int i = poz; i > 0; i -= i & (-i)) s += aib[i];
  return s;
}
int main() {
  int q, ok = 0, l = 0;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    poz[v[i]].push_back(i);
    if (v[i] == 0) ok = 1;
    if (first[v[i]] == 0) first[v[i]] = i;
    last[v[i]] = i;
  }
  if (first[q] == 0 && ok == 0) {
    printf("NO");
    return 0;
  }
  for (int i = 1; i <= q; i++) {
    if (first[i] != 0) {
      int a = query(last[i]) - query(first[i] - 1);
      if (a > 0) {
        printf("NO");
        return 0;
      }
    }
    for (int j = 0; j < poz[i].size(); j++) update(poz[i][j]);
  }
  for (int i = 1; i <= n; i++) m.insert(i);
  for (int i = q; i >= 1; i--) {
    if (first[i] == 0) continue;
    it = m.lower_bound(first[i]);
    l = 0;
    while (it != m.end()) {
      if (*it > last[i]) break;
      sol[*it] = i;
      v1[++l] = *it;
      it++;
    }
    for (int j = 1; j <= l; j++) m.erase(m.find(v1[j]));
  }
  if (first[q] == 0) {
    int t = 0;
    for (int i = 1; i <= n; i++)
      if (sol[i] == 0) t = i;
    if (t == 0) {
      printf("NO");
      return 0;
    }
    sol[t] = q;
  }
  for (int i = 2; i <= n; i++)
    if (sol[i] == 0) sol[i] = sol[i - 1];
  for (int i = n - 1; i >= 1; i--)
    if (sol[i] == 0) sol[i] = sol[i + 1];
  int a = 1;
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", sol[i]);
  return 0;
}
