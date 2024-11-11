#include <bits/stdc++.h>
using namespace std;
int n, p, q, x[100005], y[100005], z[100005], o;
set<int> v[100005];
void d(int a) {
  if (z[a] || y[a] || x[a] > 2) return;
  if (x[a] < 2)
    x[*v[a].begin()]++;
  else
    y[*v[a].begin()] = 1;
  v[*v[a].begin()].erase(a);
  if (v[*v[a].begin()].size() == 1) d(*v[a].begin());
  z[a] = 1;
}
int main() {
  cin >> n;
  for (int a = 1; a <= n - 1; a++) {
    cin >> p >> q;
    v[p].insert(q);
    v[q].insert(p);
  }
  for (int a = 1; a <= n; a++)
    if (v[a].size() == 1) d(a);
  for (int a = 1; a <= n; a++)
    if (!z[a] && v[a].size() > 2) o = 1;
  if (o)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
