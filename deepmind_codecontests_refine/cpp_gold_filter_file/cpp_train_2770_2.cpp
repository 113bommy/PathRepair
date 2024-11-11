#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
int n, k, m, ad;
pair<int, int> p[109], a[109];
int gin(int w) {
  for (int i = 0; i < n; i++) a[i] = p[i];
  pair<int, int> x = p[w];
  sort(a, a + n, cmp);
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      id = i;
      break;
    }
  }
  int add = ad;
  while (id < k) {
    if (id == n - 1) break;
    add -= a[id].first - a[id + 1].first + 1;
    if (add < 0) break;
    swap(a[id], a[id + 1]);
    id++;
  }
  if (a[id].first > 0 && id < k)
    return 1;
  else
    return 0;
}
int in(int w) {
  for (int i = 0; i < n; i++) a[i] = p[i];
  a[w].first += ad;
  a[w].second = m;
  pair<int, int> x = a[w];
  sort(a, a + n, cmp);
  for (int i = 0; i < k; i++) {
    if (a[i] == x && a[i].first > 0) return 1;
  }
  return 0;
}
int proc(int x) {
  if (gin(x))
    return 1;
  else if (in(x))
    return 2;
  else
    return 3;
}
int main() {
  cin >> n >> k >> m >> ad;
  for (int i = 0, x; i < ad; i++) {
    cin >> x;
    x--;
    p[x].first++;
    p[x].second = i;
  }
  ad = m - ad;
  for (int i = 0; i < n; i++) {
    cout << proc(i) << " ";
  }
}
