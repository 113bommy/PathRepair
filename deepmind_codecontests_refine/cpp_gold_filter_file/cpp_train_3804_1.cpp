#include <bits/stdc++.h>
using namespace std;
int a[100100], t[100100], x[100100];
pair<int, int> tt[100100];
int pot = 1, n;
map<int, int> first[500100];
void init() {
  while (pot < n) pot *= 2;
}
void insert(int leaft, int val) {
  int node = pot + leaft;
  first[node][val]++;
  node /= 2;
  while (node > 0) {
    first[node][val]++;
    node /= 2;
  }
}
void erase(int leaft, int val) {
  int node = pot + leaft;
  first[node][val]--;
  node /= 2;
  while (node > 0) {
    first[node][val]--;
    node /= 2;
  }
}
int query(int node, int l, int r, int L, int R, int val) {
  if (r < L || R < l)
    return 0;
  else if (L <= l && r <= R)
    return (first[node].count(val) == 1) ? first[node][val] : 0;
  else {
    return query(2 * node, l, (l + r) / 2, L, R, val) +
           query(2 * node + 1, (l + r) / 2 + 1, r, L, R, val);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); i++)
    scanf("%d %d %d", &a[i], &tt[i].first, &x[i]);
  for (int i = 0; i < int(n); i++) tt[i].second = i;
  sort(tt, tt + n);
  for (int i = 0; i < int(n); i++) t[tt[i].second] = i;
  init();
  for (int i = 0; i < int(n); i++) {
    switch (a[i]) {
      case 1: {
        insert(t[i], x[i]);
      } break;
      case 2: {
        erase(t[i], x[i]);
      } break;
      case 3: {
        printf("%d\n", query(1, 0, pot - 1, 0, t[i], x[i]));
      } break;
    }
  }
}
