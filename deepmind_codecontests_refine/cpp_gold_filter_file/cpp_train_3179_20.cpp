#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    v.push_back(k);
  }
  sort(v.begin(), v.end());
  if (n == 1) {
    printf("%d\n", v[0]);
    return 0;
  }
  int i;
  for (i = 0; i < (n / 2); i++) {
    printf("%d %d ", v[i], v[n - 1 - i]);
  }
  if (n & 1) printf("%d", v[i]);
  putchar('\n');
  return 0;
}
