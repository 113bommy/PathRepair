#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf(
      "%d"
      "%d",
      &n, &k);
  vector<int> v(n);
  for (int i = 0; i != n; ++i) {
    scanf("%d", &(v[i]));
  }
  std::partial_sort(v.begin(), v.begin() + k + 1, v.end(), std::greater<int>());
  int answ = v[k - 1];
  printf("%d\n", answ);
  return 0;
}
