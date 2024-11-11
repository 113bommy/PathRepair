#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 2e6 + 13, M = 1000000;
class DisjSet {
  int *rank, *parent, n, noOfSets;

 public:
  DisjSet(int n) {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    this->noOfSets = n;
    makeSet();
  }
  int noOfElement(int x) {
    int parent = find(x), counter = 0;
    for (int i = 0; i < n; i++) {
      if (find(i) == parent) counter++;
    }
    return counter;
  }
  void makeSet() {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  int noOfTotalSets() { return noOfSets; }
  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset])
      parent[xset] = yset;
    else if (rank[xset] > rank[yset])
      parent[yset] = xset;
    else {
      parent[yset] = xset;
      rank[xset] += 1;
    }
    noOfSets--;
  }
};
void solve() {
  int n, m, a, b, rm = 0;
  cin >> n >> m;
  DisjSet dj(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (dj.find(a - 1) == dj.find(b - 1)) {
      if ((dj.noOfElement(a - 1)) % 2 != 0) rm++;
    } else
      dj.Union(a - 1, b - 1);
  }
  cout << (((n - rm) % 2 == 0) ? rm : rm + 1) << "\n";
}
int main() {
  solve();
  return 0;
}
