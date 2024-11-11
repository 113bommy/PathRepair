#include <bits/stdc++.h>
using namespace std;
int n, x[100], s[100];
struct par {
  int v, id;
  bool operator<(const par &r) const { return v < r.v; }
};
vector<par> v;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    v.push_back({x[i], i});
  }
  sort(v.begin(), v.end());
  vector<par> v1 = v;
  rotate(v1.begin(), v1.begin() + 1, v1.end());
  for (int i = 0; i < (int)v.size(); i++) s[v[i].id] = v1[i].v;
  for (int i = 0; i < n; i++) {
    printf("%d", s[i]);
    i == n - 1 ? printf("\n") : printf(" ");
  }
  return 0;
}
