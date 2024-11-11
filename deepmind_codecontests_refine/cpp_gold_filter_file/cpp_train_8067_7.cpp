#include <bits/stdc++.h>
using namespace std;
int a[1005], c[1000];
vector<int> b;
vector<int>::iterator it;
int main() {
  int n, t, ma, i, j;
  scanf("%d%d", &n, &t);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  ma = 0;
  for (i = 0; i < n; i++) {
    c[a[i]]++;
    ma = max(ma, c[a[i]]);
  }
  for (i = 0; i < min(n, t); i++) {
    for (j = 0; j < n; j++) {
      if (b.size() == 0 || *b.rbegin() <= a[j])
        b.push_back(a[j]);
      else {
        it = upper_bound(b.begin(), b.end(), a[j]);
        *it = a[j];
      }
    }
  }
  printf("%d\n", (int)b.size() + ma * (t - i));
  return 0;
}
