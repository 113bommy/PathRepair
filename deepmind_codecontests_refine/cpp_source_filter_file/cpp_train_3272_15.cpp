#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, x;
  scanf("%d", &n);
  int i = n;
  while (n--) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.rbegin(), v.rend());
  for (int o = 0; o < i; o++) printf("%d ", v[o]);
  return 0;
}
