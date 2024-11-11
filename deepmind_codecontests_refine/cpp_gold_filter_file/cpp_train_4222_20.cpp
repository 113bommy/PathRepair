#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000], b[1000000], c[1000000];
int lis() {
  vector<int> v(n, 0x3f3f3f3f);
  for (int i = 0; i < n; i++) {
    int j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    v[j] = a[i];
  }
  while (v.back() == 0x3f3f3f3f) {
    v.pop_back();
  }
  return (int)v.size();
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    b[c[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    a[b[c[i] - 1]] = i;
  }
  reverse(a, a + n);
  printf("%d\n", lis());
  return 0;
}
