#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using plll = pair<ll, pll>;
using pib = pair<int, bool>;
using pdi = pair<double, int>;
using pid = pair<int, double>;
using ld = long double;
using piiii = pair<pii, pii>;
int n, m, x, y;
bool first[10];
pii a[12], b[12];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    a[i] = {x, y};
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    b[i] = {x, y};
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) continue;
      if (a[i].first == b[j].first || a[i].first == b[j].second)
        first[a[i].first] = true;
      else if (a[i].second == b[j].first || a[i].second == b[j].second)
        first[a[i].second] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (first[i]) {
      cnt++;
      x = i;
    }
  }
  if (cnt == 1) {
    cout << x << "\n";
    return 0;
  }
  memset(first, false, sizeof false);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j] == b[i]) continue;
      if (b[i].first == a[j].first || b[i].first == b[j].second)
        first[b[i].first] = true;
      else if (b[i].second == a[j].first || b[i].second == a[j].second)
        first[b[i].second] = true;
    }
  }
  cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (first[i]) {
      cnt++;
      x = i;
    }
  }
  if (cnt == 1) {
    cout << x << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    bool q = false;
    bool r = false;
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) continue;
      if (a[i].first == b[j].first || a[i].first == b[j].second)
        q = true;
      else if (a[i].second == b[j].first || a[i].second == b[j].second)
        r = true;
    }
    if (q && r) {
      cout << -1 << "\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    bool q = false;
    bool r = false;
    for (int j = 0; j < n; j++) {
      if (b[i] == a[j]) continue;
      if (b[i].first == a[j].first || b[i].first == a[j].second)
        q = true;
      else if (b[i].second == a[j].first || b[i].second == a[j].second)
        r = true;
    }
    if (q && r) {
      cout << -1 << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
  return 0;
}
