#include <bits/stdc++.h>
using namespace std;
int oo = 2e9;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(2 * n + 1, -1);
  pair<int, int> p1, p2;
  p1 = {1, n}, p2 = {n + 1, 2 * n};
  bool mode = 0;
  for (int i = 1; i <= n - 1; ++i) {
    if (!mode) {
      v[p1.first] = i;
      v[p1.second] = i;
      ++p1.first;
      --p1.second;
      mode = 1;
    } else {
      v[p2.first] = i;
      v[p2.second] = i;
      ++p2.first;
      --p2.second;
      mode = 0;
    }
  }
  for (int i = 1; i < v.size(); ++i)
    if (v[i] == -1) v[i] = n;
  for (int i = 1; i < v.size(); ++i) printf("%d ", v[i]);
  puts("");
  return 0;
}
