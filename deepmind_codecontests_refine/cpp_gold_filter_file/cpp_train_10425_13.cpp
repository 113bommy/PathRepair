#include <bits/stdc++.h>
using namespace std;
vector<long long int> parent(500005), size(500005);
void ini() {
  for (long long int i = 0; i < 500005; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}
long long int find(long long int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}
void union1(long long int x, long long int y) {
  long long int xp = find(x);
  long long int yp = find(y);
  if (xp == yp)
    return;
  else {
    if (size[xp] < size[yp]) {
      parent[xp] = yp;
      size[yp] += size[xp];
    } else {
      parent[yp] = xp;
      size[xp] += size[yp];
    }
  }
}
int main() {
  int n, i = 0, j, k;
  cin >> n >> j >> k;
  if ((j == n / 2 || j == n / 2 + 1) && (k == n / 2 + 1 || k == n / 2))
    cout << "NO\n";
  else
    cout << "YES";
}
