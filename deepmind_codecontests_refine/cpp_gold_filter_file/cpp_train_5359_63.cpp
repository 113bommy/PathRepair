#include <bits/stdc++.h>
using namespace std;
vector<int> parent(500005, -1);
vector<int> size(500005, 0);
void make_set(int i) {
  parent[i] = i;
  size[i] = 1;
}
int find_set(int i) {
  if (parent[i] == i)
    return i;
  else
    return parent[i] = find_set(parent[i]);
}
void union_set(int i, int j) {
  i = find_set(i);
  j = find_set(j);
  if (i != j) {
    if (size[i] > size[j]) swap(i, j);
    parent[i] = j;
    size[j] += size[i];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int b, g;
  cin >> b;
  set<pair<int, int>> H;
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    H.insert({x, 1});
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int x;
    cin >> x;
    H.insert({x, 2});
  }
  for (int i = 0; i < 1000005; i++) {
    if (H.count({i % n, 1}) == 1 || H.count({i % m, 2}) == 1) {
      H.insert({i % n, 1});
      H.insert({i % m, 2});
    }
  }
  if (H.size() == n + m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
