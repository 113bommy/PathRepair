#include <bits/stdc++.h>
using namespace std;
struct Ring {
  long long a, b, h;
  void show() {}
};
Ring rings[200010];
long long tree[4 * 200010];
int n;
long long query(int node, int l, int r, int x, int y) {
  if (x > r || y < l) return 0;
  if (l >= x and r <= y) return tree[node];
  int mid = (l + r) / 2;
  int left = 2 * node;
  int right = 2 * node + 1;
  return max(query(left, l, mid, x, y), query(right, mid + 1, r, x, y));
}
void update(int node, int l, int r, int id, long long value) {
  if (l > r) return;
  if (l == r)
    tree[node] = value;
  else {
    int mid = (l + r) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if (id <= mid)
      update(left, l, mid, id, value);
    else
      update(right, mid + 1, r, id, value);
    tree[node] = max(tree[left], tree[right]);
  }
}
int comp(Ring r1, Ring r2) {
  if (r1.b != r2.b) return r1.b > r2.b;
  return r1.a > r2.a;
}
int main() {
  cin >> n;
  long long count = 0;
  map<long long, long long> compr;
  vector<long long> values;
  for (int i = 0; i < n; i++) {
    cin >> rings[i].a >> rings[i].b >> rings[i].h;
    values.push_back(rings[i].a);
    values.push_back(rings[i].b);
  }
  sort(values.begin(), values.end());
  for (int i = 0; i < (int)values.size(); i++)
    if (compr.find(values[i]) == compr.end()) compr[values[i]] = ++count;
  for (int i = 0; i < n; i++) {
    rings[i].a = compr[rings[i].a];
    rings[i].b = compr[rings[i].b];
  }
  sort(rings, rings + n, comp);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x = 1, y = (int)rings[i].b - 1;
    long long sol = query(1, 1, 2 * n, x, y) + rings[i].h;
    update(1, 1, 2 * n, rings[i].a, sol);
    ans = max(ans, sol);
  }
  cout << ans << endl;
  return 0;
}
