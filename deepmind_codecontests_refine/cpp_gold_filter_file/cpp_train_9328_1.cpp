#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 100;
map<int, int> at, b, parent, num;
int find(int x) {
  if (parent[parent[x]] != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}
void union_nodes(int x, int y) {
  int xr = find(x);
  int yr = find(y);
  if (xr == yr) return;
  if (num[x] > num[y]) {
    parent[yr] = xr;
    num[xr] += num[yr];
  } else {
    parent[xr] = yr;
    num[yr] += num[xr];
  }
  return;
}
int main() {
  int n, i, k, j;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    at[arr[i]] = i;
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) b[at[arr[i]]] = i;
  for (i = 0; i < n; i++) {
    parent[i] = i;
    num[i] = 1;
  }
  for (i = 0; i < n; i++) union_nodes(i, b[i]);
  vector<int> compo[maxn];
  set<int> roots;
  for (i = 0; i < n; i++) {
    compo[find(i)].push_back(i);
    roots.insert(find(i));
  }
  cout << roots.size() << endl;
  for (set<int>::iterator it = roots.begin(); it != roots.end(); it++) {
    int root = *it;
    cout << compo[root].size() << " ";
    for (j = 0; j < compo[root].size(); j++) cout << compo[root][j] + 1 << " ";
    cout << endl;
  }
}
