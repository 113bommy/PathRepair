#include <bits/stdc++.h>
using namespace std;
int n, m;
int cn = 0;
int ver[102];
int sz[102];
int xs[102];
int ys[102];
int find(int p) {
  int root = p;
  while (root != ver[root]) root = ver[root];
  while (p != root) {
    int newp = ver[p];
    ver[p] = root;
    p = newp;
  }
  return root;
}
void unionVer(int p, int q) {
  int i = find(p);
  int j = find(q);
  if (i == j) return;
  if (sz[i] < sz[j]) {
    ver[i] = j;
    sz[j] += sz[i];
  } else {
    ver[j] = i;
    sz[i] += sz[j];
  }
  --cn;
}
int main() {
  cin >> n;
  cn = n;
  for (int i = 0; i < int(n); ++i) {
    ver[i] = i;
    sz[i] = 1;
    cin >> xs[i] >> ys[i];
    for (int j = 0; j < int(i); ++j) {
      if (xs[i] == xs[j] || ys[i] == ys[j]) {
        unionVer(j, i);
      }
    }
  }
  cout << cn - 1;
  return 0;
}
