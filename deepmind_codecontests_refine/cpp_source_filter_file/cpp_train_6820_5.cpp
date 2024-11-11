#include <bits/stdc++.h>
using namespace std;
multiset<int> v;
void elimina(int x) {
  multiset<int>::iterator it = v.upper_bound(x);
  if (it == v.begin()) return;
  it--;
  v.erase(it);
}
int main() {
  int n, a, b, c, sol = 0, x;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    v.insert(x);
    if (a + b + c < x) {
      printf("-1");
      return 0;
    }
  }
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  for (; !v.empty(); sol++) {
    multiset<int>::iterator it = v.end();
    it--;
    int s = *it;
    v.erase(it);
    if (c >= s) {
      multiset<int>::iterator it = v.upper_bound(b);
      if (it != v.begin()) it--;
      if (it == v.begin()) {
        elimina(b + c);
        continue;
      }
      it = v.upper_bound(a);
      if (it == v.begin()) {
        elimina(b + c);
        continue;
      }
      elimina(b);
      elimina(c);
    } else if (a + b >= s)
      elimina(c);
    else if (a + c >= s)
      elimina(b);
    else if (b + c >= s)
      elimina(a);
  }
  printf("%d", sol);
  return 0;
}
