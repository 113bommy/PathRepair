#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[1004];
int n, x, y;
vector<int> vec;
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) swap(x, y);
    p[i] = make_pair(y, x);
  }
  sort(p + 1, p + n + 1);
  int pr = -10000;
  for (i = 1; i <= n; i++) {
    if (p[i].second > pr) {
      vec.push_back(p[i].first);
      pr = p[i].first;
    }
  }
  printf("%d\n", vec.size());
  for (i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
  return 0;
}
