#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T &x) {
  return x.size();
}
const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double pi = acos(-1);
template <class T>
T smod(T a, T b) {
  return (a % b + b) % b;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > adj(n);
  vector<int> col(n);
  int a, b;
  vector<pair<int, int> > edges(n - 1);
  for (__typeof(0) i = (0); i < (n - 1); ++i) {
    cin >> a >> b;
    edges[i] = make_pair(a - 1, b - 1);
  }
  for (__typeof(0) i = (0); i < (n); ++i) {
    cin >> col[i];
  }
  vector<pair<int, int> > badedges;
  for (__typeof(0) i = (0); i < (n - 1); ++i) {
    if (col[edges[i].first] != col[edges[i].second]) {
      badedges.push_back(edges[i]);
    }
  }
  if (size(badedges)) {
    int root1 = badedges[0].first, root2 = badedges[0].second;
    for (__typeof(1) i = (1); i < (size(badedges)); ++i) {
      if (root1 != badedges[i].first && root1 != badedges[i].second) {
        root1 = -1;
      }
      if (root2 != badedges[i].first && root2 != badedges[i].second) {
        root2 = -1;
      }
    }
    if (root1 == -1 && root2 == -1) {
      printf("NO\n");
    } else {
      if (root1 != -1)
        printf("YES\n%d\n", root1 + 1);
      else
        printf("YES\n%d\n", root2 + 1);
    }
  } else {
    printf("YES\n");
  }
}
