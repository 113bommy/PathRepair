#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
int n, m, t;
int parent2[N], rank2[N], parent1[N], rank1[N];
bool used1[N], used2[N];
int find_set_1(int v) {
  if (v == parent1[v]) return v;
  return parent1[v] = find_set_1(parent1[v]);
}
void make_set_1(int v) {
  parent1[v] = v;
  rank1[v] = 0;
}
void union_sets_1(int a, int b) {
  a = find_set_1(a);
  b = find_set_1(b);
  if (a != b) {
    if (rank1[a] < rank1[b]) swap(a, b);
    parent1[b] = a;
    if (rank1[a] == rank1[b]) ++rank1[a];
  }
}
int find_set_2(int v) {
  if (v == parent2[v]) return v;
  return parent2[v] = find_set_2(parent2[v]);
}
void make_set_2(int v) {
  parent2[v] = v;
  rank2[v] = 0;
}
void union_sets_2(int a, int b) {
  a = find_set_2(a);
  b = find_set_2(b);
  if (a != b) {
    if (rank2[a] < rank2[b]) swap(a, b);
    parent2[b] = a;
    if (rank2[a] == rank2[b]) ++rank2[a];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m1, m2;
  cin >> n >> m1 >> m2;
  int x, y;
  for (int i = 1; i <= n; i++) {
    make_set_2(i);
    make_set_1(i);
  }
  for (int i = 0; i < m1; i++) {
    cin >> x >> y;
    union_sets_1(x, y);
  }
  for (int i = 0; i < m2; i++) {
    cin >> x >> y;
    union_sets_2(x, y);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (find_set_2(i) != find_set_2(j) && find_set_1(i) != find_set_1(j)) {
        union_sets_2(i, j);
        union_sets_1(i, j);
        ans.push_back({i, j});
      }
    }
  cout << ans.size() << "\n";
  for (auto el : ans) {
    cout << el.first << " " << el.second << "\n";
  }
}
