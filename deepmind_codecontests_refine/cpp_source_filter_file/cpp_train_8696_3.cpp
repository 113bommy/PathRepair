#include <bits/stdc++.h>
int a[100001];
struct data {
  int num;
  int dist;
  data(int n, int d) {
    num = n;
    dist = d;
  }
  data() {}
};
std::vector<data> v[100001];
int cnt = 0;
void searchTree(int loc, int dist, int root) {
  cnt++;
  for (int i = 0; i < v[loc].size(); i++) {
    data d = v[loc][i];
    if (d.num == root) continue;
    if (d.dist + dist <= a[d.num]) {
      searchTree(d.num, dist + (d.dist > 0 ? d.dist : 0), loc);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    int p, c;
    scanf("%d%d", &p, &c);
    v[i].push_back(data(p, c));
    v[p].push_back(data(i, c));
  }
  searchTree(1, 0, 0);
  printf("%d", n - cnt);
}
