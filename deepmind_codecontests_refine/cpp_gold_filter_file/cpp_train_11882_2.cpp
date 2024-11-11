#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct node {
  int n;
  int i;
  node(int n, int i) : n(n), i(i) {}
  node() {}
  bool operator<(const node& n1) const { return n < n1.n; }
  bool is_happy() const {
    int a = n;
    while (a) {
      if (a % 10 != 7 && a % 10 != 4) return false;
      a /= 10;
    }
    return true;
  }
};
node nodes[maxn];
int rev[maxn];
inline void sw(int i, int j, vector<pair<int, int> >& ans) {
  ans.push_back(pair<int, int>(nodes[i].i, nodes[j].i));
  swap(nodes[i].i, nodes[j].i);
  rev[nodes[i].i] = i;
  rev[nodes[j].i] = j;
}
int main() {
  int n;
  scanf("%d", &n);
  bool sorted = true;
  int x = -1, prev;
  for (int i = 0; i < n; i++) {
    prev = x;
    scanf("%d", &x);
    if (prev > x) sorted = false;
    nodes[i] = node(x, i);
  }
  if (sorted) {
    printf("0\n");
    return 0;
  }
  sort(nodes, nodes + n);
  for (int i = 0; i < n; i++) {
    rev[nodes[i].i] = i;
  }
  int happy = -1;
  for (int i = 0; i < n; i++) {
    if (nodes[i].is_happy()) {
      happy = i;
      break;
    }
  }
  if (happy == -1) {
    printf("-1\n");
    return 0;
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++)
    if (i != happy && nodes[i].i != i) {
      if (rev[i] != happy) sw(rev[i], happy, ans);
      sw(happy, i, ans);
    }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
  return 0;
}
