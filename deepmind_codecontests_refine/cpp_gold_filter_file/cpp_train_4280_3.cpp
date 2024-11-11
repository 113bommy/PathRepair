#include <bits/stdc++.h>
using namespace std;
long long parent[10001];
long long cnt = 0, cnt1 = 0;
void make_set(int v) { parent[v] = v; }
int find_set(int v) {
  if (v == parent[v]) return v;
  return find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b) cnt++;
  if (a != b) parent[b] = a;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int k = 1; k <= n; k++) make_set(k);
  for (int k = 1; k <= m; k++) {
    int l, t;
    cin >> l >> t;
    union_sets(l, t);
  }
  for (int k = 1; k <= n; k++)
    if (parent[k] == k) cnt1++;
  if (cnt == 1 && cnt1 == 1)
    cout << "FHTAGN!";
  else
    cout << "NO";
}
