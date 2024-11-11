#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, o, p, q = 0;
  char x[100000], y[1000000];
  scanf("%d %d", &m, &n);
  int a[m];
  std::vector<int> v;
  for (i = 0; i < m; i++) {
    scanf("%d", a + i);
    bool found = false;
    for (j = 0; j < i; j++) {
      if (v[j] == a[i]) found = true;
    }
    if (!found) {
      v.push_back(a[i]);
    }
    if (v.size() > n) v.erase(v.begin());
  }
  printf("%d\n", v.size());
  for (i = v.size() - 1; i >= 0; i--) {
    printf("%d", v[i]);
    if (i) printf(" ");
  }
  printf("\n");
  return 0;
}
