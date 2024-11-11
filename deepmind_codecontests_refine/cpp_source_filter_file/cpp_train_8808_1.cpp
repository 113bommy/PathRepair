#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int sum[2555][2555];
map<pair<pair<int, int>, pair<int, int> >, int> mp;
void add(int x, int y, int val) {
  for (int i = x; i <= n; i += (i & (-i))) {
    for (int j = y; j <= n; j += (j & (-j))) {
      sum[i][j] += val;
    }
  }
}
int query(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= (i & (-i))) {
    for (int j = y; j > 0; j -= (j & (-j))) {
      ans += sum[i][j];
    }
  }
  return ans;
}
int main() {
  srand(time(NULL));
  scanf("%d %d %d", &n, &m, &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (t == 1) {
      int u = rand() * rand();
      mp[pair<pair<int, int>, pair<int, int> >(pair<int, int>(a, b),
                                               pair<int, int>(c, d))] = u;
      add(a, b, u);
      add(c + 1, b, -u);
      add(a, d + 1, -u);
      add(c + 1, d + 1, u);
    } else if (t == 2) {
      int u = mp[pair<pair<int, int>, pair<int, int> >(pair<int, int>(a, b),
                                                       pair<int, int>(c, d))];
      add(a, b, -u);
      add(c + 1, b, u);
      add(a, d + 1, u);
      add(c + 1, d + 1, -u);
    } else {
      if (query(a, b) == query(c, d)) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
  return 0;
}
