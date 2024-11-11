#include <bits/stdc++.h>
using namespace std;
set<int> S;
set<int>::iterator ite, temp, y;
int n, k, q, ar[200005], type, id, size;
int main() {
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", ar + i);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &type, &id);
    if (type == 1) {
      size++;
      if (size == 1) {
        S.insert(ar[id]);
        ite = S.find(ar[id]);
      } else if (size <= k) {
        S.insert(ar[id]);
        if (ar[id] < *ite) ite = S.find(ar[id]);
      } else {
        if (ar[id] > *ite) {
          S.insert(ar[id]);
          temp = ite;
          ite++;
          S.erase(temp);
        }
      }
    } else {
      printf("%s", S.find(ar[id]) != S.end() ? "YES" : "NO");
    }
  }
  return 0;
}
