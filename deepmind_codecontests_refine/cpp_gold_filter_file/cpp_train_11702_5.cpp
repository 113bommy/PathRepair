#include <bits/stdc++.h>
using namespace std;
const int inf = 999999999;
vector<int> a;
int n;
int main() {
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> lis_t(n + 1, inf);
  for (int i = 0; i < a.size(); ++i)
    *lower_bound(lis_t.begin(), lis_t.end(), a[i]) = a[i];
  for (int i = 0; i <= a.size(); ++i) {
    if (lis_t[i] == inf) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
