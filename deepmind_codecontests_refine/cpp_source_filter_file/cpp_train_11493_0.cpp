#include <bits/stdc++.h>
using namespace std;
int check[50], taken[50] = {0};
vector<int> gp[50];
vector<int> v;
int find_(int x) {
  if (check[x] == x) return x;
  check[x] = find_(check[x]);
  return check[x];
}
void union_(int x, int y) {
  int a = find_(x);
  int b = find_(y);
  if (a != b) check[a] = b;
}
int main() {
  int t, i, n, m, a, b;
  for (i = 0; i < 50; i++) {
    check[i] = i;
  }
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    union_(a, b);
    taken[a] = 1;
    taken[b] = 1;
  }
  for (i = 1; i <= n; i++) {
    int leader = find_(i);
    gp[leader].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    if (taken[i] == 0) {
      v.push_back(i);
    }
  }
  int k = 0;
  for (i = 1; i <= n; i++) {
    if (gp[i].size() == 2) {
      if (k >= v.size()) {
        printf("-1");
        return 0;
      }
      gp[i].push_back(v[k++]);
    }
    if (gp[i].size() > 3) {
      printf("-1");
      break;
    }
  }
  int cnt = 0;
  for (; k < v.size(); k++) {
    if (cnt == 3) {
      printf("\n");
      cnt = 0;
    }
    printf("%d ", v[k]);
    cnt++;
  }
  if (k != 0) printf("\n");
  for (i = 1; i <= n; i++) {
    if (gp[i].size() == 3) {
      for (t = 0; t < gp[i].size(); t++) {
        printf("%d ", gp[i][t]);
      }
      printf("\n");
    }
  }
  return 0;
}
