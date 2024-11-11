#include <bits/stdc++.h>
using namespace std;
int xParents[1005];
int yParents[1005];
int parent[1005];
int subtreeSize[1005];
void init(int n) {
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
    subtreeSize[i] = 1;
  }
}
int root(int x) { return parent[x] == x ? x : parent[x] = root(parent[x]); }
void join(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  if (subtreeSize[x] < subtreeSize[y]) {
    parent[x] = y;
    subtreeSize[y] += subtreeSize[x];
  } else {
    parent[y] = x;
    subtreeSize[x] += subtreeSize[y];
  }
}
int main() {
  int numInput;
  cin >> numInput;
  init(numInput);
  for (int i = 0; i < numInput; i++) {
    int x, y;
    cin >> x >> y;
    if (xParents[x]) {
      join(i, xParents[x]);
    } else {
      xParents[x] = i;
    }
    if (yParents[y]) {
      join(i, yParents[y]);
    } else {
      yParents[y] = i;
    }
  }
  int count = 0;
  for (int i = 1; i <= numInput; i++) {
    count += parent[i] == i;
  }
  cout << count - 1 << endl;
  return 0;
}
